# tmux使用

#
prefix ？ 查看tmux预定义的快捷键列表，以及这些快捷键绑定的指令
 
 
 
 
 
 
 
 
 

一、安装
1、通过包管理器安装
2、
二、命令前缀
tmux中的快捷键是由命令前缀和命令键组成，默认命令前缀是ctrl+b。命令前缀的作用是告诉tmux，我们当前输入的命令是为了让tmux去执行，而不是让tmux里的应用程序去执行。
我们并不是将命令前缀和快捷键一起按下，而是先同时按下ctrl和b两个键，然后松开，再按下我们想要让tmux执行的命令键。
三、会话
创建关闭会话
$ tmux 创建新的会话，名字默认从零开始。不推荐这种用法，除非只是短时间使用这个会话。
$ tmux new -s session_name 或者 tmux new-session -s session_name 创建命名会话 。
$ exit 杀死当前会话，返回标准终端中。
$ tmux kill-session -t session_name 杀死指定名字的会话
分离会话、重连会话
+ prefix + d 从一个会话分离
$ tmux ls 或者 tmux list-sessoins 列出当前存在的tmux会话
$ tmux attach 如果只有一个会话，连接该会话
$ tmux attach -t session_name 连接指定名字的会话
四、常用快捷键
窗口
+ prefix + c 创建一个新的窗口并将tmux的焦点转过来
+ prefix + ， 重命名一个窗口
+ prefix + n 切换到下一个窗口（next）
+ prefix + p 切换到上一个窗口（previous）
+ prefix + number_key 切换到第几个窗口，tmux默认是从0开始计数，但是从0开始的计数的数组并不是一成不变的
+ prefix + f 通过窗口的名字查找一个窗口（find）
+ prefix + w 显示一个可视化的窗口列表，我们可以选择其中我们想要的那个窗口
$ exit 或者 + prefix + & 关闭一个窗口，后者会在状态栏给出一个确认信息（&=et=exit）。如果想完全退出一个tmux会话，必须关闭所有窗口。
面板
+ prefix + % 将当前面板左右分割（%形似左右各一半）
+ prefix + " 将当前面板水平分割
+ prefix + o 在面板之间来回切换（o形似循环）
+ prefix + 四个箭头 在面板之间切换
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
