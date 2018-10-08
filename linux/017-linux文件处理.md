# linux文件处理

## uniq命令

uniq命令用于查找或忽略文件中的重复行，一般与sort命令结合使用。

#### 语法

```shell
uniq (options) (params)
```

#### 选项

```shell
-c或——count                            在每列旁边显示该行重复出现的次数；
-d或--repeated                         仅显示重复出现的行列；
-f<栏位>或--skip-fields=<栏位>         忽略比较指定的栏位；
-s<字符位置>或--skip-chars=<字符位置>  忽略比较指定的字符；
-u或——unique                           仅显示出一次的行列；
-w<字符位置>或--check-chars=<字符位置> 指定要比较的字符。
```

## sort命令


```shell
去除重复行
sort file |uniq

查找非重复行
sort file |uniq -u

查找重复行
sort file |uniq -d

统计
sort file | uniq -c
```
