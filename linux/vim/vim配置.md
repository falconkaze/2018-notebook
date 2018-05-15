# vim配置属性解释
[vim配置入门,到豪华版vim配置](https://blog.csdn.net/renchunlin66/article/details/51592066)  
[vim配置大全](https://blog.csdn.net/darennet/article/details/41148135)
[vim配置-主题篇](https://blog.csdn.net/u012948976/article/details/50991933)

## filetype——文件类型检测
vim中执行```filetype```可以查看vim的文件类型检测功能是否打开；```set filetype```查看当前文件是什么类型。默认属性：```detection:ON plugin:OFF indent:OFF```
* detection：默认情况vim会对文件自动检测文件类型，也就是你看到的'detection:ON'，如需关闭:filetype off。还有一种方式就是在文件内容中指定，Vim会从文件的头几行自动扫描文件是否有声明文件类型的代码，如在文件的首行加入 //vim: filetype=HTML，当作注释写入，以致于不影响文件的编译，这样Vim不通过文件名也能检测出文件是什么类型
* plugin：当plugin状态为"ON"时，那么就会在Vim的运行时环境目录下加载该类型相关的插件。比如为了让Vim更好的支持Html编程，就需要下载一些Html相关的插件。vim中执行 :filetype plugin on
* indent：不同类型文件有不同的方式，比如Python要求使用4个空格作为缩进，而Html使用2个空格作为缩进，那么indent就可以为不同文件类型选择合适的缩进方式。你可以在Vim的安装目录的indent目录下看到定义了很多缩进相关的脚本。vim中执行 :filetype indent on。 

以上三个参数，可以写成一行filetype plugin indent on在_vimrc文件中写入。
## vim中tab、空格相关设置
1. shiftwidth，这个是用于程序中自动缩进所使用的空白长度指示的。一般来说为了保持程序的美观，和下面的参数最好一致。同时它也是符号移位长度的制定者。
2. tabstop，简写为ts，定义tab所等同的空格长度，一般来说最好设置为8，因为如果是其他值的话，可能引起文件在打印之类的场合看起来很别扭，除非设置了expandtab，也就是把tabs转为空格。
3. softtabstop，这个参数是为了整合上面两个参数。一旦设置了softtabstop的值，插入的是空格和tab的混合，具体如何取决于设定的softtabstop。举个栗子，如果设定softtabstop=8，那么按下tab，键入的就是正常的一个制表符。如果设定 softtabstop=16,那么插入的就是两个制表符；如果softtabstop=12,那么插入的就是一个制表符加上4个空格；如果 softtabstop=4呢？那么一开始，插入的就是4个空格，此时一旦你再按下一次tab，这次的四个空格就会和上次的四个空格组合起来变成一个制表符。换句话说，softtabstop是“逢8空格进1制表符”,前提是你tabstop=8。
4. expandtab，多人开发时，为了代码风格尽量保持一致，一般不允许在代码中使用tab符，而以空格代替。这个配置就是将tab转为tab长度的多个空格。
## autocmd
autocmd,即自动命令，在发生一些事情的时候自动执行，类似于钩子函数。
* BufNewFile 表示创建新文件时触发
* BufRead 读取一个文件时
用法：
```
autocmd BufNewFile,BufRead *.html,*.htm,*.css,*.js set noexpandtab tabstop=2 shiftwidth=2  
```
