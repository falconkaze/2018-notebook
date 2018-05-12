* 命名规则：文件名和文件夹名，小写加下划线。
* python两种模式：命令行模式，python交互模式。在命令行下输入python回车，就能进入交互模式，退出命令为exit()。交互模式会把每一行python代码的结果打印出来（不需要print），多用于调试代码或者学习语法命令等。
* python代码有两种运行方式：
```
$ python file_name	这种方式不需要在文件第一行指定解释器（也就是python）
$ chmod a+x file_name	这种方式需要在文件第一行指定解释器（#!/usr/bin/env python3），然后运行./file_name
```
这里文件名后缀不是必要的，linux中的文本后缀是为了方便人们使用，对于程序来说没用。
* python中的双引号和单引号都可以用于表示字符串。
* python中指定编码的方式：
```
# coding:utf-8 或者
# -*- coding:utf-8 -*-
```

