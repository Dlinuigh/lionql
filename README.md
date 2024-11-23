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
