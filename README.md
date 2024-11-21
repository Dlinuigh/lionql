# LionQL

## 数据库的实现清单

### 存储管理

实现文件存储：使用固定大小的页（如 4KB）来存储表数据和索引。

1. 文件系统支持：文件应当支持简单的读写操作。
2. 支持分页存储，确保每个表的数据被组织在若干页内。

### SQL语句支持

基础 SQL 支持：

1. 支持 SELECT、INSERT、UPDATE、DELETE 操作。
2. 支持简单的条件筛选（WHERE）、排序（ORDER BY）和分页（LIMIT）。
3. 支持表的创建、删除和修改（CREATE、ALTER、DROP）。
4. 基本的 JOIN 支持（INNER JOIN 或 LEFT JOIN）。

### 索引支持

基础索引功能：

1. 实现单列索引和复合索引（对于查询速度优化）。
2. 支持 B+ 树索引（适用于范围查询、排序）。

### 事务管理

基本的事务支持：

1. 实现 ACID 特性：原子性、一致性、隔离性、持久性。
2. 支持 BEGIN、COMMIT、ROLLBACK 语句。
3. 简单的锁机制和日志管理（如 WAL）来保证数据一致性和崩溃恢复。

### 新特性

#### JSON支持

##### JSON数据类型

##### JSON查询支持

##### JSON更新支持

### 扩展支持

#### 支持嵌套查询

#### 触发器和存储过程

#### 高级查询优化

## 实现过程记录

### [2024-11-21]

昨日大致疏通了flex和bison的共同运作流程，与基本语法。
今日：

1. flex的正则表达式与posix的基本一致，唯一问题是^$会作用于一整个字符串，而不是当前的token.
2. union中的结构可以在c中定义使用，只对需要解析的部分生效，比如有一些无类型token将直接忽略，但是仍然要占据$n的编号，比如exp operator exp中exp是表达式可以有值，而operator假设只是一个符号，无类型token，那么就是%type<char*> exp和 %token operator,类型是struct exps{char* a; char* b;}，
3. <<EOF>>是夺取系统对eof结束的处理，如果你没有任何处理的需求，就不要这么做。
4. 空语句可以做什么？ stmt_list: stmt END stmt_list中stmt_list支持空语句就能去掉stmt END这个情况。但是对于有类型的不能定义空语句