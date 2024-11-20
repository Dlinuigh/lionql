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