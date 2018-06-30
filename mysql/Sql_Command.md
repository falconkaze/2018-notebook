#### 数据库相关操作

#### 表相关操作

#### 列相关操作
增加列
```
alter table table_name add column_name varchar(30);
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
alteir table table_name change old_name new_name type; 
```
删除列
```
alter table table_name drop column column_name;
```

