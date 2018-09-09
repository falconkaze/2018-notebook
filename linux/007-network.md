# linux网络相关

##　查看DNS

```
nm-tool 可以查看ip地址，子网掩码，网关，DNS等信息。不知道为什么使用下面的命令看到的DNS跟这个命令看到的不一样，需要了解一下DNS相关的知识。

cat /etc/resolv.conf

nslookup 127.0.0.1 | grep Server

dig
```

## linux静态ip的设置

[mac静态ip的设置](https://www.jianshu.com/p/61b30a78852b?deDup445843=1)
