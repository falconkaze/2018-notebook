# git stash使用

## 常用命令

```bash
git stash  # 保存工作区和暂存区的文件（新增的文件，如果没有被git管理，不会被保存）
git stash list # 列出所有的stash记录
git stash save name # 保存时指定名称
git stash clear # 清空所有stash记录
git stash drop stash@{1} # 清除指定的stash记录
```

## 语法

```bash
git stash list [<options>]
git stash show [<stash>]
git stash drop [-q | --quiet] [<stash>]
git stash (pop | apply) [--index] [-q | --quiet] [<stash>]
```
