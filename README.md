[![C/C++ CI](https://github.com/Dlinuigh/lionql/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/Dlinuigh/lionql/actions/workflows/c-cpp.yml)
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

### [2024-11-22]

SELECT X FROM X WHERE X COMPARE X ;
INSERT INTO X (X, ...) VALUES (X, ...), ... ;
UPDATE X SET X = X, ... ;
CREATE DATABASE X ;
CREATE TABLE X ( X INT PRIMARY KEY, ...) ;
CREATE VIEW X;
CREATE INDEX X ON X(X) ;
ALTER TABLE X ADD X DECIMAL(10, 2) ;
ALTER TABLE X MODIFY X SMALLINT ;
ALTER TABLE X RENAME CLOUMN X TO X ;
ALTER TABLE X DROP COLUMN X ;
ALTER TABLE X RENAME TO X
DROP DATABASE X ;
DROP TABLE X ;
DROP VIEW X ;
DROP INDEX X ;
INNER JOIN X ON X.X = X.X, ...
LEFT JOIN X ON X.X = X.X, ...
ORDER BY X ASC LIMIT X OFFSET X
AS X
LEFT(X, X)
AVG(X)
USING (X, ...)

-> STMT
INSERT INTO X VALUES (X)
UPDATE X SET X = X

-> TABLE (同时也可以单独成为语句)
SELECT X FROM TABLE
-> TABLE (不能单独成句)
X INNER JOIN X ON CONDITION
X LEFT JOIN X ON CONDITION

-> RESTRICT
WHERE CONDITION
ORDER BY X ASC
LIMIT X
OFFSET X

总结一下，基本上涵盖了所有的预期目标了。然后几个基本的语句解析完成，代码的变量也进行了调整。
目前的问题是：
1. 注意减少使用空表达式
2. 不要一味追求重复代码少而使用空表达式，会造成二义性问题
3. token的识别，flex中一些更具体的token会相互竞争，确保没有token出现冲突。
4. 预计后面会大幅度减少剩余的非类型token,使用类型可以最大限度避免非类型token导致的问题，比如不能在有类型规则里不返回该类型数据
5. vscode又卡顿闪退了，所以我换成vim了，初步体验基本没有问题，我将一些常用的快捷键映射了
6. 明天可以完成语句解析，接下来就是执行。执行的里的存储也是需要一起设计的。

### [2024-11-23]

flex中通过给yylval的成员也就是union定义的类型赋值可以传递给bison中的token.而bison中一般来说$n获取不同位置的token指代的值，$$则是将之传递给规则的窗户。而当规则只有一个token时就会自动传递不需要任何人工干预，除非需要。
我想到一个处理方法：将字符串的对应的内存空间重复利用，并找到一个字符串指针对应的空间将其改造为能够存放所有内容的指针。这个token必须尽早的发现并扩充后传递。在后续的过程中不断有字符添加到这个空间，其余的指针对应的空间直接free,在解析的最后进行依次free就能搞定。好处是不用重复进行malloc、realloc了。唯一问题是如何设计这样一个初始字符串。如果有办法获得文件头，那么直接让文件头指针扩充就行，后续不断入栈，但是很难，找到这样一个指针是很难的，而且不现实，更好的做法是创建一个全局指针。这个可以，而且成本非常小。
还有一个问题：规则中尽量创建类型规则、类型token这一点到底是否正确，目前来说，对于那些规则匹配了大量简易字符的，最好的处理就是在flex匹配阶段将值传递到结构体中，否则后续的处理将会1苦不堪言，对每一种情况都需要处理。
我突然理解了无符号token,所有能够单独形成规则的都需要无符号，所有只依附其他形成规则的都不需要
Bison解析过程出现的无用可能的原因：
1. 该规则没有被使用
2. 该规则有问题，少了|等符号
3. 该规则的成员其中的孩子有问题，这个可以追溯到最初，当然也可能这个导致了其他的规则无用

### [2024-11-24]

今天做存储，首先是存储的建模：
1. Database是最顶层的存储类，他会管理所有的表和索引（segment）。
2. 对于一个表（segment）他会有多个extend，每一个extend有固定数量（16）个page（4KB）作为基础的存储结构。多个extend会存储在一个文件中。此外如果page有不等长数据的溢出首先尝试存放在一个特殊的溢出文件中，溢出文件分成不同的块，采用链式索引。一个segment的溢出存放在一个溢出文件中。
3. 采用列存储模式，一列占用一个page.那么例如，4KB存储一个tinyint（1B）可以存放4K条记录。注意这是未压缩的结果。压缩是将文件压缩后存放在硬盘中，而从硬盘读取压缩文件到内存后在进行解压得到原始数据也就是4KB这种。
4. 在上面的存储中，使用列存储意味着每次插入将会将不同列的数据单独存放在多个page中，每一个列一个page这基本上是最后的处理。而一个列可能占用多个page.一个extend可能无法存放全部列，这个时候多个extend就会被使用。
5. 上面的全部设计中，压缩是物理层的处理将不会被软件层感知。而数据的存放与索引则是同样不能被感知，即存放时如果发现page存满了需要换页存放，如果extend存满了需要创建新extend而溢出区也不会被感知。对于溢出区是否采用多文件再议。
6. 对于多page可以采用链式存储。同样的extend扩展也可以这样做。

目前还没有进度因为并没有头绪，这里用一些自然语言来描述一个数据库的存储。
database.liondb
[database]
name: database-name
table: table-1
index: index-1

[table]
name: table-1
member: 
    name: id
    type: int
    size: 8
    page-start: 0 后续插入数据的时候补充的内容，首页，链式
extends: [0]

extend:
    id: 0
    page-start: 0

[index]
name: index-1

database.dat
page-id 0
is-fix 1
dirty [0 0 0]
empty [0 0 0]
0011 0023 0045

page-id 1
is-fix 0
dirty [0 0 0]
empty [0 0 0]
01 02 03

database.vardat
[01 data 04]
[02 other 05]
...
[04 data 00]
[05 other 00]

### [2024-11-25]

设计了基本雏形，详细内容可以看代码。
这里约定数据库由三部分文件：1. 数据库的元信息，2. 数据库的定长数据，3. 数据库不定长数据
元信息单独存放一个文件是因为如果和数据在一起容易造成更新信息困难除非定一个较大的空间。
不定长数据使用定长的块进行链式索引，单独存放没有问题。当然也可以存放在一起，但是一般而言
不定长数据的压缩和定长可能有不同，大多是字符串，0-1比特流，很难进行压缩。
.meta 文件存放元信息, .dat存放定长数据, .vardat存放不定长数据

### [2024-12-07]

暂时可以回归这个没有完成的项目上。
之前我的疑问应该有体现在代码中，主要是数据库的标准设计对我的影响太大了，还没有权衡。
Grok2感觉上没有特别优势，但是非常非常简洁，Chatgpt非常非常多废话，一言不合就贴代码。
而Grok2完全不会这样，甚至完全不贴代码，非常舒服。
唯一问题：需要打开X.对于那些缺少资料的，非常笨，很多错误。
而我们只需要一篇文档就能了解用法全部，所以AI还是在很多地方劣于人类的。

有一个点，我应该从数据的角度入手，数据从代码中转移到内存中，在从内存中转移到硬盘中。
全程进行跟踪。

### [2024-12-08]

今天看代码发现自己的设计并没有什么问题，只是没有写完数据的持续化代码，文件没有跟踪调试。
所以之后的工作围绕着让代码运行和数据的追踪。这样就完成了存储结构的设计。
之后的问题是满足数据库的范式的，想当然很容易，但是如何在代码中体现很难。主要的方向估计是
增加日志系统，类似于ext文件系统的，对数据的操作进行追踪。控制数据的写入读取。
