#### 数据库相关操作

#### 表相关操作

#### 列相关操作
增加列
```
alter table table_name add column_name varchar(30);
alter table table1 add id int auto_increment primary key 自增字段，一定要设置为primary key. 
```
修改列类型
```
alter table table_name alter column column_name varchar(20);
```
```
alter table table_name modify column_name varchar(20);
```
修改列的名称
```
EXEC sp_rename 'table_name.column1','column2'
```
```
alter table table_name change old_name new_name type; 
```
删除列
```
alter table table_name drop column column_name;
```

#### 索引相关操作

[mysql 索引](https://www.cnblogs.com/tianhuilove/archive/2011/09/05/2167795.html)
添加索引
```
ALTER TABLE table_name ADD INDEX index_name (column_list);
ALTER TABLE table_name ADD UNIQUE (column_list);
ALTER TABLE table_name ADD PRIMARY KEY (column_list);
```

修改索引名字
```
# mysql5.7及之后版本
ALTER TABLE tbl_name RENAME INDEX old_index_name TO new_index_name

# mysql5.7之前版本
ALTER TABLE tbl_name DROP INDEX old_index_name
ALTER TABLE tbl_name ADD INDEX new_index_name(column_name)
```
