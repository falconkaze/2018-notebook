# linux配置
## 科学上网
[github地址](https://github.com/googlehosts/hosts)
## 常用配置文件位置及作用
#### 用户环境配置
在用户各自的home目录下～/.bashrc、~/.profile、~/.xinitrc或~/.xprofile中设置自己的用户环境，如果文件不存在可以新建。几种配置文件的区别在于生效的时间。
* .bashrc 每次启动终端的时候
* .profile 每次启动系统的时候
* .xinitrc 每次使用startx启动x界面的时候
* .xprofile 每次使用图形登录管理器登录的时候
## 语言、字体及输入法配置
#### 显示语言设置

#### 输入法配置
安装fcitx输入法框架
```# pacman -S fcitx fcitx-configtool```
安装搜狗输入法
```# pacman -S fcitx-sogoupinyin```
配置输入法,在~/.xinitrc或者~/.xprofile中添加代码,具体选择看常用配置文件那一条。
```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
fcitx & exec startxfce4
```
如果不行，运行fcitx-diagnose，按照其输出该装的装，该设的设。
如果经常在vim下使用fcitx,可以在~/.vimrc中添加如下代码,在退出,进入插入模式的时候自动切换开关fcitx
```
"##### auto fcitx  ###########
let g:input_toggle = 1
function! Fcitx2en()
   let s:input_status = system("fcitx-remote")
   if s:input_status == 2
      let g:input_toggle = 1
      let l:a = system("fcitx-remote -c")
   endif
endfunction

function! Fcitx2zh()
   let s:input_status = system("fcitx-remote")
   if s:input_status != 2 && g:input_toggle == 1
      let l:a = system("fcitx-remote -o")
      let g:input_toggle = 0
   endif
endfunction

set ttimeoutlen=150
"退出插入模式
autocmd InsertLeave * call Fcitx2en()
"进入插入模式
autocmd InsertEnter * call Fcitx2zh()
"##### auto fcitx end ######
```
#### 字体
```
# pacman -Ss font			搜索所有字体
# pacman -S ttf-dejavu			推荐
# pacman -S wqy-zenhei
# pacman -S wqy-microhei	
# pacman -S adobe-source-code-pro-fonts	据说是一款适合编程显示的字体
```

## 声音设置
## 显示设置
#### 调节屏幕亮度
```
echo 1000 > /sys/class/backlight/intel_backlight/brightness # 屏幕亮度调到1000
cat  /sys/class/backlight/intel_backlight/max_brightness # 查看屏幕亮度最大值
```
# 显示设置
#### 调节屏幕亮度
```
echo 1000 > /sys/class/backlight/intel_backlight/brightness # 屏幕亮度调到1000
cat  /sys/class/backlight/intel_backlight/max_brightness # 查看屏幕亮度最大值
```

