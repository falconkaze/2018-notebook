# linux网络相关

* [arch wiki](https://wiki.archlinux.org/index.php/Network_configuration_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

## 查看网络设备

```shell
ls /sys/class/net
ifconfig
ip link
iw dev  # 查看无线设备
```

##　查看DNS

```
nm-tool 可以查看ip地址，子网掩码，网关，DNS等信息。不知道为什么使用下面的命令看到的DNS跟这个命令看到的不一样，需要了解一下DNS相关的知识。

cat /etc/resolv.conf

nslookup 127.0.0.1 | grep Server

dig
```

## linux静态ip的设置

[mac静态ip的设置](https://www.jianshu.com/p/61b30a78852b?deDup445843=1)
