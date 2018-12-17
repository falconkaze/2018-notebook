# linux bash history

* [Linux下查看命令行历史记录](https://blog.csdn.net/love_xsq/article/details/50620703)

bash的历史记录保存在用户目录的`.bash_history`文件中。

## 相关配置

具体的配置解释可以使用`man bash`查看

```bash
export HISTCONTROL=ignoreboth   # 不保存连续的重复命令
export HISTSIZE=10000           # history记录数
export HISTFILESIZE=10000       # 文件记录数(与上面不一样，每次退出bash的时候，才会把命令写入.bash_history文件，而退出之前，history也可以查到刚刚输入的命令)
export HISTIGNORE='ls'          # history中不记录ls命令
```

## 相关命令

```bash
history -c # 清除本次登陆bash的所有命令
```
