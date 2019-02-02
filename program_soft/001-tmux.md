# tmux使用

* [arch wiki](https://wiki.archlinux.org/index.php/Tmux)
* [赖明星博客](http://mingxinglai.com/cn/2012/09/tmux/)
* [Tmux 快速教程](http://blog.jeswang.org/blog/2013/06/24/tmux-kuai-su-jiao-cheng/)

## 介绍

tmux是一个优秀的终端复用软件，可以分屏，可以让当前任务在后台进行，即使关闭了当前终端也不影响。这两点作用非常适合操作远程机器，分屏可以在一个ssh连接中模拟多个终端来使用，另外可以保存当前的工作环境，下次登录远程机器可以直接恢复（只要远程机器没有关闭），这一点能够避免网络不稳定时丢失工作进度。

安装比较简单，用电脑所使用的发行版的包管理器就可以。

```shell
sudo pacman -S tmux
```

tmux使用C/S模型构建，现在很多软件都是使用这种模式，比如vim的代码提示插件Ycmd和docker等等。由于tmux的数据都存放在server端，所以断连不会丢失当前环境。tmux有几个概念：
* server    输入tmux命令就是开启了一个服务器
* session   一个服务器包含多个会话
* window    一个会话包含多个窗口
* pane      一个窗口包含多个面板

在开启了tmux服务器后，会创建一个会话，一个窗口，这个窗口仅包含一个面板。

## 常用命令

```shell
# list
tmux list-keys 列出所有快捷键和tmux命令
tmux list-commands 列出所有tmux命令及参数
tmux info 列出所有session，window，pane，运行的进程号等
tmux source-file ~/.tmux.conf 加载指定的配置文件

# session
tmux new -s name    创建新的session并指定名字
tmux new -s name -d 后台创建session
tmux ls             列出所有session
tmux list-sessions   列出所有session
tmux attach -t name 连接指定的session
tmux attach         连接上一个session
tmux switch -t session_name 切换到指定的session。如果在tmux命令行使用，不需要前面的tmux。不推荐使用这个命令，如果需要切换session，可以使用快捷键prefix+w
tmux detach (prefix+d) 离开当前session

# window
tmux list-windows   列出当前session的所有windows
tmux select-window -t :0-9(或者name)
tmux rename-window(prefix + ,)

# pane
tmux split-window (prefix + ")
tmux split-window -h (prefix + %)
tmux swap-pane -[UDLR] (prefix + { or }) 按方向交换pane
tmux select-pane -[UDLR] 按方向选择pane
tmux select-pane -t :.+  选择下一个数字的pane
```

## 常用快捷键

tmux的所有指令，都包含一个前缀，只有按了前缀之后，系统才知道接下来的指令是发送给tmux的。默认的前缀键是`Ctrl+b`。

```shell
<C>-b ?          显示快捷键帮助
<C>-$            重命名session
<C>-b w          显示所有会话和窗口，j，k上下移动，回车选择，ESC退出
<C>-b s          以菜单形式显示和选择会话
<C>-b t          显示时钟，这个命令主要用于无图形化界面的机器上
<C>-b d          断开tmux会话，这时这个会话还在后台运行，可以通过tmux attach连接

<C>-b <C>-o      调整面板位置，按住Ctrl不放，然后依次按b，o即可。
<C>-b b          依次切换焦点
<C>-b 方向键     切换焦点
<C>-b <C>-方向键 调整面板大小
<C>-b ;          切换到最后一个使用的面板

<C>-b "          横向分割面板（上下布局）
<C>-b %          纵向分割面板（左右布局）
<C>-b space      采用下一个内置布局

<C>-b q          显示面板的编号

<C>-b x          关闭当前面板
<C>-b &          关闭当前窗口

<C>-b !          把当前面板变为窗口
<C>-b c          创建新窗口
<C>-b num        选择几号窗口
<C>-b p          上一个窗口
<C>-b n          下一个窗口
<C>-b l          切换到最后一个使用的窗口
```

## tmux状态栏

tmux状态栏会显示当前session名，当前session的所有窗口以及当前位于哪个窗口。

## 配置

tmux的配置文件是`~/.tmux.conf`，配置完后重启tmux生效，或者先按前缀键，然后输入`:`，进入命令行模式，在命令行模式下输入

```tmux
source-file ~/.tmux.conf
```

或者在配置文件中加入下面这句，prefix+r重新加载配置文件

```tmux
bind r source-file ~/.tmux.conf \;display "Reload!"
```

#### 复制模式

使用：
1. 按 `prefix+[`  进入复制模式
2. 按 `space` 开始复制，移动光标选择复制区域
3. 按 `Enter` 复制并退出复制模式
4. 光标移动到指定位置，按 `prefix+]` 粘贴

在配置文件中加入下面命令，可以在复制的时候像vim一样移动
```tmux
set -g mode-keys vi
```

>从我用vim开始，就相信这世界上有些人比你自己还了解你自己想要什么，所以乔老爷子才能做 出让世人尖叫的产品，所以我经常浏览高手的.vimrc文件，我用了tmux不到3天就发现，它怎么 不能最大化当前pane?就像vim里的ZommWinPlugin.vim插件一样，你按下某键，当前窗口就最大 化了，获得最大可视界面。当目前为止，就还没有发现我有需求而别人没有的，同样，已有前人 找到的解决办法，方法如下：
```tmux
# zoom pane <-> window
#http://tmux.svn.sourceforge.net/viewvc/tmux/trunk/examples/tmux-zoom.sh
bind ^z run "tmux-zoom"
##
```

$ exit 杀死当前会话，返回标准终端中。
$ tmux kill-session -t session_name 杀死指定名字的会话
分离会话、重连会话
+ prefix + d 从一个会话分离
四、常用快捷键
窗口
+ prefix + ， 重命名一个窗口
+ prefix + f 通过窗口的名字查找一个窗口（find）
$ exit 或者 + prefix + & 关闭一个窗口，后者会在状态栏给出一个确认信息（&=et=exit）。如果想完全退出一个tmux会话，必须关闭所有窗口。
面板
面板布局
tmux中有几个默认布局：
* even-horizontal 把所有面板均匀地水平排列，从左到右
* even-vertical 把所有面板均匀地垂直排列，从上到下
*  main-horizontal 在顶部创建一个非常大的面板，其余面板变为小面板水平地放在底部
* main-vertical 在左侧创建一个非常大的面板，其余面板变为小面板垂直地放在右侧
* tiled 把所有面板大小均等地在屏幕上显示
+ prefix + space键 循环切换这些面板布局
关闭面板
在面板中输入exit，或者prefix + X（大写），如果当前窗口只有这一个面板的话，还会同时关闭这个窗口
在杀死指定面板时，会收到确认提示，如果某个面板被阻塞了，或者不会再使用了，杀死它
命令模式
prefix + : 进入命令模式
$ new-window -n name 创建一个新的窗口并命名
$ new-window -n name "top" 创建一个窗口并执行top命令，但是当我们按下q关闭top程序的时候，这个tmux窗口也会被一起关闭，如果想让top关闭后窗口依然存在，可以修改配置文件。#
