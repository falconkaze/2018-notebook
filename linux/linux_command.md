# linux命令大全
## 系统相关
#### 查看端口占用并释放
[linux 查看端口占用情况](https://www.cnblogs.com/wangtao1993/p/6144183.html)
查看指定端口的使用情况
```
lsof -i 8080				查看8080端口的使用情况
netstat -tunlp |grep 8080	查看8080端口的使用情况
```
查看所有端口的使用情况
```
netstat -tunlp				查看所有端口的使用情况
```
-t (tcp) 仅显示tcp相关选项
         -u (udp)仅显示udp相关选项
         -n 拒绝显示别名，能显示数字的全部转化为数字
         -l 仅列出在Listen(监听)的服务状态
         -p 显示建立相关链接的程序名
```
杀死进程
```
kill -9 进程PID
```
