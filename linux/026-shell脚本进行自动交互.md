# linux使用脚本来交互

* [shell 脚本中经常要用到ssh。怎么能不交互的输密码呢？](https://blog.csdn.net/thriller/article/details/52794824?utm_source=blogxgwz3)
* [Shell脚本交互之：自动输入密码](https://blog.csdn.net/zhangjikuan/article/details/51105166)
* [expect spawn、linux expect 用法小记](https://www.centos.bz/2013/07/expect-spawn-linux-expect-usage/)

## ssh自动登陆

#### 利用ssh配置

1. 编辑目标机的`authorized_keys`文件
  在文件中添加自己ssh公钥

2. 编辑`~/.ssh/config`文件（可选）

  ```config
  Host test-host
    HostName 127.0.0.1
    User root
    IdentityFile ~/.ssh/id_rsa
    ForWardAgent yes
    ServerAliveInterval 150
  ```

#### 参考另一篇笔记（ssh-add）

## sudo命令自动输入密码（利用管道符，要求命令有对应的参数接收密码）

  ```shell
  echo "my_password" | sudo -S pacman -Syu
  ```

## 利用重定向输入密码，要求命令有对应的参数接收

  *  实现ftp自动登录并运行ls指令的用法如下：
  ```shell
  ftp -i -n 192.168.21.46 <<EOF
  user zjk zjk123
  ls
  ```

## 使用`expect`模拟交互过程

  `spawn`是expect的语句，执行命令之前要加这句。

  ```shell
  #! /usr/bin/env expect
  set timeout 30
  spawn ssh -l user-name 127.0.0.1
  expect "password:"
  send "test-password\r"
  interact
  ```
