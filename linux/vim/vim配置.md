# vim配置属性解释
[vim配置入门,到豪华版vim配置](https://blog.csdn.net/renchunlin66/article/details/51592066)  
[vim配置大全](https://blog.csdn.net/darennet/article/details/41148135)
[vim配置-主题篇](https://blog.csdn.net/u012948976/article/details/50991933)

#### filetype——文件类型检测
vim中执行```filetype```可以查看vim的文件类型检测功能是否打开；```set filetype```查看当前文件是什么类型。默认属性：```detection:ON plugin:OFF indent:OFF```
* detection：默认情况vim会对文件自动检测文件类型，也就是你看到的'detection:ON'，如需关闭:filetype off。还有一种方式就是在文件内容中指定，Vim会从文件的头几行自动扫描文件是否有声明文件类型的代码，如在文件的首行加入 //vim: filetype=HTML，当作注释写入，以致于不影响文件的编译，这样Vim不通过文件名也能检测出文件是什么类型
* plugin：当plugin状态为"ON"时，那么就会在Vim的运行时环境目录下加载该类型相关的插件。比如为了让Vim更好的支持Html编程，就需要下载一些Html相关的插件。vim中执行 :filetype plugin on
* indent：不同类型文件有不同的方式，比如Python要求使用4个空格作为缩进，而Html使用2个空格作为缩进，那么indent就可以为不同文件类型选择合适的缩进方式。你可以在Vim的安装目录的indent目录下看到定义了很多缩进相关的脚本。vim中执行 :filetype indent on。 

以上三个参数，可以写成一行filetype plugin indent on在_vimrc文件中写入。

