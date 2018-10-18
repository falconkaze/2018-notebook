# mysql配置

## 中文乱码

1. 查看字符集

  ```
  SHOW VARIABLES LIKE 'character_set_%';
  ```

2. 修改配置文件 /etc/mysql/my.cnf

  ```
  sudo vi /etc/mysql/my.cnf
  ```

在`[client]` `[mysqld_safe]` `[mysqld]`下分别加入

  ```
  [client]
  default-character-set=utf8

  [mysqld_safe]
  default-character-set=utf8

  [mysqld]
  character-set-server=utf8
  ```

3. 重启服务

  ```
  sudo service mysql restart
  ```

## mysql外网访问

修改配置文件，重启服务

```shell
# 把bind-address改为0.0.0.0(不限制ip)，或者改为特定的ip
sudo vim /etc/mysql/my.cnf
```


