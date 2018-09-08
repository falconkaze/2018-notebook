# limit

limit语句的参数：偏移量，记录数。记录数为-1时，表示返回起始处后的所有数据。当偏移量大的时候，性能就会大大降低。

## 原因

```mysql
select * from table_name limit 10000,10
```

这条sql的执行逻辑是：
* 从数据表中读取第N条记录添加到数据集中
* 重复第一步到N=10000+10
* 根据offset抛弃前面的10000条记录
* 返回剩下的10条记录

首先，数据库的数据存储并不是像我们想象中那样，按表按顺序存储数据，一方面是因为计算机存储本身就是随机读写，另一方面是因为数据的操作有很大的随机性，即使一开始数据的存储是有序的，经过一系列的增删查改之后也会变得凌乱不堪。所以数据库的数据存储是随机的，使用 B+Tree， Hash 等方式组织索引。所以当你让数据库读取第 10001 条数据的时候，数据库就只能一条一条的去查去数。

## 解决方式

* 记录上次分页的主键（或者根据查询条件获取第一条记录的主键），然后根据主键定位起始记录位置，然后再取出所要的记录。缺点：主键必须为递增（或者说必须有递增的索引）。  

  实例：
  ```mysql
  select * from table_name where user = user_name limit 10000,10;
  ```

  - 子查询方式
    ```mysql
    select * from table_name where id in (select id from table_name where user = user_name limit 10000,20);
    SELECT * FROM articles WHERE  id >=  
    (SELECT id FROM articles  WHERE category_id = 123 ORDER BY id LIMIT 10000, 1) LIMIT 10 
    ```

  - join方式
    ```mysql
    SELECT * FROM `content` AS t1   
    JOIN (SELECT id FROM `content` ORDER BY id desc LIMIT ".($page-1)*$pagesize.", 1) AS t2   
    WHERE t1.id <= t2.id ORDER BY t1.id desc LIMIT $pagesize; 
    ```

