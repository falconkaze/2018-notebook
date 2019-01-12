# linux终端下git状态提示及自动补全

* [Linux 终端 Git 分支提示和自动补全相关脚本文件](https://my.oschina.net/jean/blog/853627)

```shell
curl https://raw.githubusercontent.com/git/git/master/contrib/completion/git-prompt.sh -o ~/.git-prompt.sh
curl https://raw.githubusercontent.com/git/git/master/contrib/completion/git-prompt.sh -o ~/.git-completion.bash
```

`~/.bashrc`追加代码

```bash
# 显示分支官方实现
GIT_PS1_SHOWDIRTYSTATE=true
GIT_PS1_SHOWCOLORHINTS=true
if [ -f ~/.git-completion.bash ]; then
  source ~/.git-prompt.sh
# 这一行中间中括号部分语法与linux终端提示符语法相同，可以自行修改
  PROMPT_COMMAND='__git_ps1 "[\t][\u@\h:\w]" "\\\$ "'
fi

# 显示分支另一种实现，如果用官方实现可以不用这段代码
git_branch () { git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\(\1\)/'; }
HOST='\033[02;36m\]\h'; HOST=' '$HOST
TIME='\033[01;31m\]\t \033[01;32m\]'
LOCATION='\033[01;34m\]`pwd | sed "s#\(/[^/]\{1,\}/[^/]\{1,\}/[^/]\{1,\}/\).*\(/[^/]\{1,\}/[^/]\{1,\}\)/\{0,1\}#\1_\2#g"`'
BRANCH='\033[00;33m\]$(git_branch)\[\033[00m\]\n\$ '
PS1=$TIME$USER$HOST$LOCATION$BRANCH
PS2='\[\033[01;36m\]>'

# GIT 命令&分支自动完成
if [ -f ~/.git-completion.bash ]; then
  . ~/.git-completion.bash
fi
```
