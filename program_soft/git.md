# git基本常识及命令
## git简介
#### git的提交代码方式
git有两种提交代码的方式，https和git。git提交代码安全又高效，优先选择。将远程代码clone下来的时候，仓库名就有这两种选择。也可以手动修改。
```
git remote -v		查看远程仓库（前缀就是提交提交方式）

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

