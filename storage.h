#pragma once
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <map>
#include <memory>
#include <fstream>
#include <ranges>
#include <vector>
#define PAGE_SIZE 4096
#define EXT_SIZE 16
#pragma pack(push, 1)
struct PageHeader {
  int id{};          // global (in a database) id of a page
  int next_page{0};  // 0 means the last page
  int column_id{-1}; // table's column id
  int term_num{0};   // combine when available
  bool is_fix{true}; // 固定数据page存储的就是data,否则就是VarData的id
  int len{0};
};
struct VarData { // 定长数据的基本长度，2xint的占比较低就行。
  int32_t id; // 两个必要的额外开销，存储在数据中，数据可以是128B一块
  int32_t next;
  int8_t data[120]; // 加上上面的组成128B
};
struct ExtendHeader {
  int id{};         // global (in a database) id for a extend
  int page_start{}; // 起始page编号
  std::bitset<EXT_SIZE> dirty{0x0}; // page的写入情况位图，帮助确定数据是否为脏
  std::bitset<EXT_SIZE> empty{(0x1 << EXT_SIZE) - 1}; // page是否为空
};
struct Column {
  const char *name;
  const char *type_name;
  int len{0};
  int scale{0};
  int start_page_id{-1};
  int id{0};
};
struct TableHeader {
  const char *name{};
  int id;
  std::vector<Column> members{};
};
struct DatabaseHeader {
  const char *name{};
  std::vector<int> tables{};
};
#pragma pack(pop)
// 添加一个log类用来调试，并且记录操作到文件。
class LionLog{
public:
  LiongLog(){}
  static void Info(std::string message, std::string func){
    std::cout << func << std::endl;
    std::cout << __func__ << message << std::endl;
  }
  static void Debug(std::string message, std::string func){
    std::cout << func << std::endl;
    std::cout << __func__ << message << std::endl;
  }
private:

};
/*
  为什么需要Page类，便于修改数据和写入数据，用于建立page缓冲区和查找表。
  当页面的数据完成写入后，也就是dirty时上一层需要定期检查并写入。
  不能等到页换出时才进行
*/
class Page { // 物理层
public:
  Page() {}
  void insertData(std::string value) {
    int index =
        std::find_if(empty.begin(), empty.end(), [](bool b) { return b; }) -
        empty.begin();
    memcpy(data + index * type_size, value.c_str(), type_size);
    empty.at(index) = false;
  }
  bool isValid() const { return id == -1; }
  int getId() const { return id; }

private:
  int id{-1};
  std::vector<bool> empty{}; // 由于数据的长度未知所以需要使用vector
  int8_t data[PAGE_SIZE];
  int type_size{};
};
/*
  Space是物理层的顶层抽象，他掌握所有的结构的元信息，但是不会存储任何
  实质性数据，所有的数据可以被临时存放到一个ext中，但是不会读取更多的，
  可以读取一个ext,也不会读取更多的信息。这两个缓冲区由Space直接管理。
  有一个问题，上面的ext只是一个指代，真正的意思是一簇page,可能来自多个ext
  Space存储所有的头部信息，这是最关键的，有一个问题，io一般要求连续读，
  而不是随机读，比如来自多个ext的数据，这就需要建立一个page的查找表，
  只加载那些修改后的，利用LRU之类技术控制page的载入。
  Space是存放在内存中的，当他发生了修改不会立马写入磁盘，而是定期写入，
  或者等到数据达到一定量再写入。根据页表的规则是，换出时写入。
  Space的向量头设计似乎对后续的B树索引没有好处，问题点在于B树需要准确地
  找到page或者ext的位置，将pages的索引必然不是好主意，只有使用全局page_id,
  可是如果发生了表删除，这个索引id失效了也无法回收，当然了好处是时间局部
  全局有效性，这样只要记得更新就不会有问题。
  Space与Database的关系，Space不依附于某个特定的db,而是程序的一开始就生成了
  db使用这个抽象类，从创建的时候就借助Space完成。
*/
class Space { // 物理层
public:
  Space() {}
  ~Space() {
    rfp.close();
    wfp.close();
  }
  void useDatabase(int index){
    cur_db = index;
  }
  // 写入db的元信息到文件
  void createDatabase(const char *name, const char* filename) { dbs.emplace_back(name); dbs_file.push_back(filename);}
  // 写入表的基本信息到文件
  void createTable(const char *name, int id) { tables.emplace_back(name, id); }
  void insertData(std::vector<std::string> &line, int table_id,
                  const char *member_name) {
    int index = std::find_if(
                    tables.begin(), tables.end(),
                    [table_id](TableHeader &_t) { return _t.id == table_id; }) -
                tables.begin();
    std::vector<Column> members = tables.at(index).members;
    int column_id = std::find_if(members.begin(), members.end(),
                                 [member_name](Column &col) {
                                   return not strcmp(member_name, col.name);
                                 }) -
                    members.begin();
    int page_id = members.at(column_id).start_page_id;
    Page &page = findPage(page_id, members.at(column_id), true);
    for (auto &v : line) {
      page.insertData(v);
    }
  }
  void addMember(Column &member, int table_id) {
    int index = std::find_if(
                    tables.begin(), tables.end(),
                    [table_id](TableHeader &_t) { return _t.id == table_id; }) -
                tables.begin();
    tables.at(index).members.push_back(member);
    createPage(member);
  }

private:
  int g_page_id{};
  int g_ext_id{};
  int g_seg_id{};
  int cur_db{};
  const char* meta_surfix = ".meta";
  const char* fixdata_surfix = ".dat";
  const char* vardata_surfix = ".vardat";
  std::vector<PageHeader> pages{};
  std::vector<ExtendHeader> exts{};
  std::vector<DatabaseHeader> dbs{};
  std::vector<TableHeader> tables{};
  std::vector<Page> buffer{EXT_SIZE};
  std::bitset<EXT_SIZE> dirty{0x0};
  std::bitset<EXT_SIZE> empty{(0x1 << EXT_SIZE) - 1};
  std::bitset<EXT_SIZE> access{(0x1 << EXT_SIZE) - 1};
  // 读取文件，只是获得文件指针，具体的读取通过loadpage完成。  
  void readData() {
    std::string filename{dbs.at(cur_db).name};
    filename.append(meta_surfix);
    std::ifstream rfp(filename);
  }
  void writeMeta() {
    std::string filename{dbs.at(cur_db).name};
    filename.append(meta_surfix);
    std::ofstream wfp(filename, std::ios::binary);
    // 写入db元信息
    wfp.write(reinterpret_cast<const char*>(dbs.at(cur_db)), sizeof(DatabaseHeader));
    // 写入table元信息
    for(auto& _t: tables){
      wfp.write(reinterpret_cast<const char*>(_t), sizeof(TableHeader));
    }
    // 写入ext元信息
    for(auto& _e: exts){
      wfp.write(reinterpret_cast<const char*>(_e), sizeof(ExtendHeader));
    }
    wfp.close();
  }
  void writeFixData() {}
  void writeVarData() {}
  // 加载硬盘中的page数据到缓冲区，返回缓冲区page的index
  int loadPage(){}
  // 存储缓冲区Page到硬盘
  void storePage(int index){}
  Page &findPage(int page_id, Column& member, bool write) {
    // 查找缓冲区内匹配页
    int index = -1;
    for (auto [i, p] : std::views::enumerate(buffer)) {
      if (p.isValid()) {
        if (p.getId() == page_id) {
          index = i;
        }
      }
    }
    // 缺页，首先检查空页
    auto invert = ~empty;
    size_t _tmp_id = invert._Find_first();
    if (_tmp_id < EXT_SIZE) {
      index = _tmp_id;
      // 空页的两种可能，存在后续页面用于存储；需要新增页
      createPage(member);
    }
    // 缺页，apply enhanced clock algorithm
    bool found = false;
    do {
      for(int i=0; i<EXT_SIZE; ++i){
        if (not access.test(i)) {
          if (not dirty.test(i)) {
            index = i;
            found = true;
            break;
          }
        }
      }
      if(found){
        break;
      }
      for(int i=0;i<EXT_SIZE;++i){
        if (not access.test(i)) {
          index = i;
          found = true;
          break;
        }
      }
      if(not found){
        access = 0x0;
      }
    } while (not found);
    access.set(index);
    if (write) {
      dirty.set(index);
    }
    return buffer.at(index);
  }
  void createExtend() { exts.emplace_back(++g_ext_id, ++g_page_id); }
  void createPage(Column& member) { pages.emplace_back(++g_page_id, 0, member.id, 0, member.len!=-1, member.len); }
};
class Table { // 软件层
public:
  std::string name{};
  Table(const char *_name, int _id, std::shared_ptr<Space> &_space)
      : id(_id), name(_name), space(_space) {
    space->createTable(_name, id);
  }
  void addMember(Column &member) {
    member.id = g_column_id++;
    members.push_back(member);
    space->addMember(member, id);
  }
  // 此处待议，考虑到情况实际上将存储的细节交给物理层更好
  void insertData(std::vector<std::string> &line) {
    for (auto &m : members) {
      // 数据转移到物理层
      space->insertData(line, id, m.name);
    }
  }

private:
  int id{};
  int g_column_id{0};
  std::shared_ptr<Space> space;
  // 列可以发生：增加、删除、改名、移动
  std::vector<Column> members{};
};
class Database { // 软件层
public:
  std::string name{};
  Database(const Database &) = default;
  Database(Database &&) = default;
  Database &operator=(const Database &) = default;
  Database &operator=(Database &&) = default;
  explicit Database(const char *_name, std::shared_ptr<Space> &_space)
      : name(_name), space(_space) {}
  // 目前测试无特殊附加
  void createTable(const char *_name, std::vector<Column> list,
                   std::shared_ptr<Space> _space) {
    std::unique_ptr table =
        std::make_unique<Table>(_name, g_table_id++, _space);
    for (auto &m : list) {
      m.len = get_type_len(m);
      table->addMember(m);
    }
    tables.push_back(std::move(table));
  }
  // 必须使用右值引用，暗示该数据易失
  void insertData(const char *table_name,
                  std::initializer_list<std::vector<std::string>> &&data) {
    std::unique_ptr<Table> *table =
        std::find_if(tables.begin(), tables.end(),
                     [table_name](std::unique_ptr<Table> &_t) {
                       return not strcmp(_t->name.c_str(), table_name);
                     })
            .base();
    for (auto line : data) {
      table->get()->insertData(line);
    }
  }

private:
  int g_table_id{};
  int g_index_id{};
  std::shared_ptr<Space> space;
  std::vector<std::unique_ptr<Table>> tables{}; // 存储不同的table
  std::vector<ExtendHeader> extends{};
  std::map<const char *, int> type_len{
      {"INT", 4}, {"DATE", 8}, {"CHAR", 0}, {"VARCHAR", -1}, {"DECIMAL", 0},
  };
  int get_type_len(Column &type) {
    int len = type_len[type.type_name];
    if (len) {
      return len;
    } else {
      return type.len;
    }
  }
};
/*
  Space如何影响软件层，将Space放到软件层的每一个地方，这样能够获得最基本的信息，
  由于软件层的分层，信息越往上越少，（内部信息），而外部信息是相反。
*/
class Storage {
public:
  explicit Storage(const std::shared_ptr<Space> &_space) : space(_space) {}
  void createDatabase(const char *name) {
    db.emplace_back(std::make_unique<Database>(name, space));
    space->createDatabase(name);
  }
  void useDatabase(const char *name) {
    cur_db = std::find_if(db.begin(), db.end(),
                          [name](std::unique_ptr<Database> &_d) {
                            return not strcmp(_d->name.c_str(), name);
                          }) -
             db.begin();
    space->useDatabase(cur_db);
  }
  void createTable(const char *name, std::vector<Column> list) {
    db.at(cur_db)->createTable(name, list, space);
  }
  // data需要使用move,
  void
  insertData(const char *table_name,
             std::initializer_list<std::vector<std::string>> &&data) const {
    
    db.at(cur_db)->insertData(table_name, std::move(data));
  }

private:
  int cur_db{};
  std::shared_ptr<Space> space;
  std::vector<std::unique_ptr<Database>> db;
};
#endif
