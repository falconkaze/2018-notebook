# linux setleds命令（使用命令开关小键盘）

详细参考`man setleds`

语法：
`setleds [-v] [-L] [-D] [-F] [{+|-}num] [{+|-}caps] [{+|-}scroll]`

num表示小键盘，caps标识大小写，scroll是历史遗留，是用来在翻页的时候固定光标的，现在基本用不到。

这个命令只能在tty中使用，在终端模拟器中使用会报错。

```
setleds -D +num   # 开启小键盘并设置默认开启小键盘

setleds           # 查看当前键盘三个状态
setleds [-F] +num # 开启小键盘但是不修改默认配置
setleds -L +num   # 只开启小键盘灯，不修改小键盘状态。用来灯与配置之间的对应关系。
setleds -L        # 恢复led灯与键盘状态之间的关系
```

运行X界面时启动小键盘，修改`.xinitrc`文件。在启动桌面之前，添加下面这句。

```bash
setleds -D +num
```

这句应该是在系统启动的时候执行的（没测试过）。
```
INITTY=/dev/tty[1-8]
for tty in $INITTY; do
  setleds -D +num < $tty
done
```
