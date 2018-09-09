# mysql时间字段优化

[MYSQL数据库时间字段INT，TIMESTAMP，DATETIME性能比较](http://www.piaoyi.org/database/MYSQL-INT-TIMESTAMP-DATETIME.html)

一般来说，时间字段使用int，timestamp，datetime三种类型来存储。

性能比较如下：

* MyISAM引擎，无索引的情况下，效率从高到低：`int>UNIX_TIMESTAMP(timestamp)>datetime(直接使用时间比较，而不是转为时间戳比较)>timestamp(直接和时间比较)>UNIX_TIMESTAMP(datetime)`

* MyISAM引擎，有索引的情况下，效率从高到低：`UNIX_TIMESTAMP(timestamp)>int>datetime>timestamp>UNIX_TIMESTAMP(datetime)`

* InnoDB引擎，没有索引的情况下(不建议)，效率从高到低：`int > UNIX_TIMESTAMP(timestamp) > datetime（直接和时间比较） > timestamp（直接和时间比较）> UNIX_TIMESTAMP(datetime)`

* InnoDB引擎，建立索引的情况下，效率从高到低：`int > datetime（直接和时间比较） > timestamp（直接和时间比较）> UNIX_TIMESTAMP(timestamp) > UNIX_TIMESTAMP(datetime)`

总结：对于MyISAM引擎，采用`UNIX_TIMESTAMP(timestamp)`比较；对于InnoDB引擎，建立索引，采用`int`或`datetime`直接时间比较。
