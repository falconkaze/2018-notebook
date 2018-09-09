# linux时间设置

## 查看时间

```
date 查看系统时间
hwclock 查看硬件时间
```

## 时区设置

```
cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
```

## 时间同步

```
hwclock --hctosys    硬件时间同步到系统时间
hwclock --systohc    系统时间同步到硬件时间
ntpdate  0.cn.pool.ntp.org 系统时间与网络时间同步
```
