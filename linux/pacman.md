# pacman包管理器
## pacman简介
## pacman命令
安装软件
```
pacman -S package1 package2		安装指定软件包
pacman -S extra/package			安装指定仓库的指定软件包
```
删除软件
```
pacman -R package				删除指定软件包，保留依赖
pacman -Rs 软件包				删除指定软件包，及其所有没有没有被其他软件包使用的依赖

```
