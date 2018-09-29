# vim插件使用及配置

[Vim安装YouCompleteMe插件](https://blog.csdn.net/qq_33505303/article/details/68131862?locationNum=15&fps=1)

## Vundle安装与使用

安装
```
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```

### 配置说明

配置文件：

```vim
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'file:///home/gmarik/path/to/plugin'

call vundle#end()
```


插件类型：

* [vim-script仓库](http://vim-scripts.org/vim/scripts.html)的插件
* github上非vim-script仓库的插件
* 不在github上的插件
* 本地的插件

不同的插件管理方式：

* 在vim-script仓库的，只需要写出仓库名
* 在其他用户仓库的，需要写出用户名和仓库名
* 不在github上的，需要写出git全路径
* 本地的插件需要写出全路径（浏览器可以访问的那种路径）

### 常用命令

```
:PluginInstall		安装插件，追加！更新插件或者使用PluginUpdate
:PluginList			列出所有已配置的插件
:PluginSearch foo	搜索foo，追加！清除本地缓存
:PluginClean		清除未使用插件，需要确认，追加！不用确认
```

## YouCompleteMe

[YouCompleteMe gitbub地址](https://github.com/Valloric/YouCompleteMe)


### 安装


## NERDTree

* 按？打开帮助文档
* 按j、k在NERDTree上下移动，o或回车打开或关闭文件夹
* :vsp 在右侧打开一个分屏，:sp 在下面打开一个分屏 
* <c-w>j ，<c-w>k, <c-w>h, <c-w>l 按键分别向上、下、左、右分屏移动。 <c-w>= 均分屏幕

## ctrlp.vim

* <f5> 更新目录缓存。
* <c-f> / <c-b> 在模式之间切换
* <c-d> 在”完整路径匹配“ 和 ”文件名匹配“ 之间切换
* <c-r> 在“字符串模式” 和 “正则表达式模式” 之间切换
* <c-j> / <c-k> 上下移动光标
* <c-t> 在新的 tab 打开文件
* <c-v> 垂直分割打开
* <c-x> 水平分割打开
* <c-p>, <c-n> 选择历史记录
* <c-y> 文件不存在时创建文件及目录
* <c-z> 标记/取消标记， 标记多个文件后可以使用 <c-o> 同时打开多个文件
