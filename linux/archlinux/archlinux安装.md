# archlinux安装

### 准备工作

##### 测试网络

archlinux的安装离不开网络，测试网络：

```
ping www.baidu.com
ping 8.8.8.8
```

##### 测试系统时间

查看系统时间
```
timedatectl status
```

如果时间不对，开启ntp服务（每隔11分钟进行一次网络对时）

```
timedatectl set-ntp true
```

##### 测试存储设备

查看存储设备状态。在sda节点下，每一个带数字的节点（sda1）都是该物理硬盘分出来的区.

```
#lsblk
#fdisk -l
```

### 硬盘

##### 硬盘分区

将sda分为一个mbr类型的分区

```
#cfdisk
```

进入交互界面，先new出分区，容量全分了，然后改成bootable（也就是把那个星号打上），然后把分区信息write进去，最后quit即可。

或者使用fdisk命令分区

```
#fdisk /dev/sda
```

创建分区表
Command(m for help):输入o并按下enter
然后创建分区：依次是 n、默认、默认、默认、确定分区大小（+15G）
预览分区
Command(m for help):p
向磁盘中写入这些改动
Command(m for help):w
**注意**：linux中的硬盘分区必须挂载才可以使用，包括U盘。

##### 格式化分区

格式化成ext4文件系统

```
mkfs.ext4 /dev/sda1
```

格式化交换分区
```
# mkswap /dev/sdax
```

开始使用格式化分区
```
#swapon /dev/sdax
```

##### 挂载分区

把根目录挂载在/mnt目录下
```
# mount /dev/sda1 /mnt
```

先创建目录再挂载

```
mkdir /mnt/home
mount /dev/sda2 /mnt/home
```

### 连接网络

##### 有线网络

十一、网络设置

# ip link
找到网络设备（例如：enp0s3）
# ip link set enp0s3 up
# dhcpcd enp0s3
# systemctl enable dhcpcd@enp0s3.service
##### 无线网络

* 使用wifi-menu连接网络
**注意**：镜像包系统内默认会包含wifi-menu相关包,但是下载的默认系统中不会包含,可以在配置系统的时候,使用wifi-menu命令查看所需包.如果忘记可以使用U盘挂载系统安装依赖包.

### 安装系统
使用国内的镜像源可以获得更快的下载速度。修改镜像源需要编辑/etc/pacman.d/morrotlist文件。可以利用正则表达式grep工具来将中国的源取出来，首先切换到软件源所在目录：
```# cd /etc/pacman.d```
用grep取出中国的源，用-A参数会用分割线分割每一条匹配，因此需要再次使用grep工具去掉前一次结果产生的分隔符
```grep -A 1 '##.*China' mirrorlist|grep -v '\-\-'> mirrorlist2```
然后把中国的源放在镜像列表的最前面，这样先反过来，将原来的镜像源加在中国的源后面，然后替换掉之前的文件。
```
cat mirrorlist>>mirrorlist2
mv mirrorlist2 mirrorlist
```
镜像源修改完之后需要刷新一下pacman的缓存
```
pacman -Syy
pacman -S archlinux-keyring
```
安装基本系统，-i参数是在安装前进行确认，全选即可。basa-devel是开发包，包括很多程序员需要的常用工具。
```pacstrap -i /mnt base base-devel```
生成fstab分区表
```# genfstab -U -p /mnt >> /mnt/etc/fstab```
### 配置系统
root到新系统开始配置
```# arch-chroot /mnt /bin/bash```
##### 区域和时间设置
区域设置需要设置两个文件，locale.gen和locale.conf文件。  
先用nano打开/etc/locale.gen文件，然后取消en_US.UTF-8、zh_CN.UTF-8、zh_TW.UTF-8三行的注释。然后运行locale-gen命令生成locale信息。
```
# nano /etc/locale.gen
# locale-gen
```
然后生成一个locale.conf文件，这里最好使用英文，使用别的语言可能会导致终端乱码
```# echo LANG=en_US.UTF-8 > /etc/locale.conf```
选择时区
```# tzselete		（4、9、1）```
将时区软链接到自己的时区
```# ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime```
将时间标准设置为UTC
```# hwclock --systohc --utc```
设置主机名
```# echo myhostname > /etc/hostname```
然后编辑etc/hosts文件，添加下面内容
```
#<ip-address>   <hostname.domain.org>   <hostname>
127.0.0.1   localhost.localdomain   localhost   myhostname
::1     localhost.localdomain   localhost   myhostname
```
启动有线网服务
```# systemctl enable dhcpcd.service```
设置root密码
使用不带参数的passwd可以设置root密码。
```# passwd```
##### 安装启动加载器
先安装grub
# pacman -S grub
安装完成后，使用下面命令，注意不要指定分区数字：
```grub-install --target=i386-pc --recheck /dev/sda。（--target=i386-pc指示grub-install是为使用BIOS的系统安装. 推荐一直标明这点以防混淆.）```
生成配置文件，默认的配置文件可以适应大部分情况
```# grub-mkconfig -o /boot/grub/grub.cfg```
##### 退出并重启系统
# exit
# umount -R /mnt
# reboot
### 图形界面安装
进入系统后首先更新软件包
# pacman -Syu
安装Xorg
```
# pacman -S xorg 或
# pacman -S xorg-server xorg-xinit
```
安装显卡驱动
```
# pacman -S xf86-video-vesa # 通用显卡驱动，不提供任何2D和3D加速功能
# pacman -S xf86-video-intel # Intel
# pacman -S xf86-video-nouveau # Nvidia
# pacman -S nouveau-dri
# pacman -S xf86-video-ati # Ati
```
安装声卡驱动键入
```# pacman -S alsa-utils```
安装XFCE4桌面套件
```# pacman -S xfce4```
安装登陆管理器，这样不需要手动去输入输入启动X的命令
```# pacman -S slim```
安装sudo让普通用户无需切换执行一些root用户指令
```# pacman -S sudo```
安装中文字体
```# pacman -S wqy-zenhei（文泉骈-正黑）```
注意设置终端字体，默认字体会重叠。
添加普通用户并设置密码
```
# useradd -m -g users -G wheel -s /bin/bash 用户名
# passwd 用户名
```
为用户添加sudo的相关权限，在/etc/sudoers文件中添加：
```用户名 ALL=(ALL) ALL ```
保存重启
为了避免出现没有~/.xinitrc的情况，所以可以从系统中复制一个（或者直接新建一个）
# cp /etc/skel/.xinitrc或
# touch ~/.xinitrc
添加exec startxfec4
