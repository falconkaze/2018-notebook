# git基本常识及命令
## git简介
#### git的提交代码方式
git有两种提交代码的方式，https和git。git提交代码安全又高效，优先选择。将远程代码clone下来的时候，仓库名就有这两种选择。也可以手动修改。
```
git remote -v		查看远程仓库（前缀就是提交提交方式）
```
## 远程分支管理
查看远程分支
```
git branch -r		列出所有远程分支
git branch -a		列出所有分支，包括本地分支
git branch -vv		查看本地分支关联（跟踪）的远程分支之间的对应关系。
```
删除远程分支
```
git branch -r -d origin/branch_name
git push origin:branch_name		只有这一句就可以。
```
拉取远程分支并创建本地分支
```
# 新建并切换分支，这种方法创建的本地分支会和远程分支建立映射关系。
git checkout -b local_branch origin/branch_name
# 新建分支不切换，不会建立映射关系
git fetch origin remote_branch:local_branch
```
建立本地分支和远程分支的映射关系
```
git branch -u origin/branch_name
git branch --set-upstream-to origin/branch_name
```
撤销本地分支和远程分支的映射关系
```
git branch --uset-upstream
```
### 远程代码与本地合并
使用fetch
```
git fetch origin master:temp	将远程的master分支下载到本地新建的分支temp上，不切换
git diff temp
git merge temp
```
pull相当于fetch加merge。
```
git pull origin master
```
