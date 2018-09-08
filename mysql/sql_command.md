# MYSQL命令大全
## 基本操作
* 连接MySQL：
  ```shell
  mysql -h localhost -P port -u root -p123456
  ```
* 获取当前MySQL版本和系统时间：
  ```mysql
  select version(),current_date; 
  ```
* 刷新数据库：
  ```mysql
  flush privileges;
  ```
命令本质上的作用是将当前user和privilige表中的用户信息/权限设置从mysql库(MySQL数据库的内置库)中提取到内存里。MySQL用户数据和权限有修改后，希望在"不重启MySQL服务"的情况下直接生效，那么就需要执行这个命令。通常是在修改ROOT帐号的设置后，怕重启后无法再登录进来，那么直接flush之后就可以看权限设置是否生效。而不必冒太大风险。

### 用户相关
[MySQL创建用户与授权](https://www.jianshu.com/p/d7b9c468f20d)
* 创建用户:
  ```mysql
  create user 'username'@'host' identified by 'password';
  ```
host:本地用户使用localhost,网络用户指定ip地址,%表示可以从任意远程主机登录
* 刷新权限:
  ```mysql
  flush privileges;
  ```
* 授予用户指定数据的所有权限:
  ```mysql
  grant all privileges on `database`.* to 'username'@'localhost' identified by 'password';
  ```
* 授予用户制定数据库的指定权限:
  ```mysql
  grant select,insert on databasename.tablename to 'username'@'host' with grant option;
  ```
* 查看用户表
```mysql
SELECT User, Host, Password FROM mysql.user;
SELECT DISTINCT User FROM mysql.user;
```

在ubuntu服务器下，MYSQL默认只允许本地登录，需要修改配置文件。
  ```
  # Instead of skip-networking the default is now to listen only on  
  # localhost which is more compatible and is not less secure.  
  # bind-address       = 127.0.0.1     #注释掉这一行就可以远程登录了  
  ```
### 表相关
  ```
  CREATE TABLE `t_user` (
  	`Id` int(11) NOT NULL AUTO_INCREMENT,  -- 自增
  	`username` varchar(18) NOT NULL unique,  -- 唯一性约束
  	`password` varchar(18) NOT NULL,
  PRIMARY KEY (`Id`)
  )ENGINE=InnoDB DEFAULT CHARSET=utf8;
  ```
删除表
  ```
  drop table table_name;
  ```
给建好的表加唯一索引
  ```
  ALTER TABLE `t_user` ADD unique(`username`);
  ```
修改表名
  ```
  ALTER TABLE table_name RENAME TO new_table_name;
  ```
修改字段默认值


## 基本的CRUD操作
### 插入
* insert关键字
批量插入:
  ```
  INSERT INTO user
  (`id`,`name`,`sex`)
  VALUES
  (1,'user001',0),
  (2,'user002',1)
  ```
* ON DUPLICATE KEY UPDATE
插入更新：
  ```
  INSERT INTO user
  (`id`,`name`,`sex`)
  VALUES
  (1,'user001',0)
  ON DUPLICATE KEY UPDATE
  (`name`='user001',`sex`=0)
  ```
批量插入更新
  ```
  INSERT INTO user
  (`id`,`name`,`sex`)
  VALUES
  (1,'user001',0),
  (2,'user002',1)
  ON DUPLICATE KEY UPDATE
  `name`=VALUES(`name`),
  `sex`=VALUES(`sex`)
  ```
**注意**：
* VALUES()函数只有在INSERT…UPDATE语句中有意义，其他时候会返回null。
* 若多个索引都冲突，则只有一条记录被修改。示例如下：
  ```
  create table test(
  id int not null primary key,
  num int not null UNIQUE key,
  tid int not null
  );
  insert into test values(1,1,1), (2,2,2);
  insert into test values(1,2,3) on duplicate key update tid = tid + 1;
  因为a和b都是唯一索引，插入的数据在两条记录上都产生了冲突，然后执行后只有第一条记录被修改。
  ```
* REPLACE关键字  
REPLACE相当于将DELETE和INSERT合二为一，形成一个原子操作，这样就可以不必考虑在同时使用DELETE和INSERT时添加事务等复杂操作了。  
在使用REPLACE时，表中必须有唯一索引，而且这个索引所在的字段不能允许空值，否则REPLACE就和INSERT完全一样的。  
在执行REPLACE后，系统返回了所影响的行数，如果返回1，说明在表中并没有重复的记录，如果返回2，说明有一条重复记录，系统自动先调用了DELETE删除这条记录，然后再记录用INSERT来插入这条记录。如果返回的值大于2，那说明有多个唯一索引，有多条记录被删除和插入。  
REPLACE的语法和INSERT非常的相似，还支持UPDATE的SET操作
  ```
  REPLACE INTO user (`id`,`name`,`sex`) VALUES(1,'user007',0);
  REPLACE INTO user (`id`,`name`,`sex`) VALUES(1,'user007',0),(2,'user009',1);
  REPLACE INTO user SET id = 123, name = '赵本山', age = 50;
  ```

参考：
[ON DUPLICATE KEY UPDATE重复插入时更新](https://blog.csdn.net/txj236/article/details/53842730)
