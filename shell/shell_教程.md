# shell教程  
【参考文献】
【1】 [shell教程——菜鸟教程](http://www.runoob.com/linux/linux-shell-variable.html)

shell是一个用c语言编写的程序，是用户使用linux的桥梁。shell既是一种命令语言，又是一种程序设计语言。shell脚本（shell scripts）是一种为shell编写的脚本程序。业界所说的shell通常是指shell脚本。  
脚本语言的运行，两种方法：
* 作为执行程序：
```
chmod +x ./test.sh	#使脚本具有执行权限
./test.sh			#执行脚本
```
**注意**：一定要写成./test.sh，而不是test.sh，运行其他二进制程序也一样。直接写成test.sh，linux系统会去PATH中去寻找该脚本，用./test.sh就是告诉系统，在当前目录下执行。（实际上就是告诉系统执行文件的路径，.表示当前路径，..表示上级目录）。
* 作为解释器参数，这种方式是直接指定解释器运行指定脚本。这个时候，文件可以没有执行权限。类似的有source命令：source在当前bash环境下读取并执行指定文件中的命令，此文件可以没有执行权限。source可以被命令 . 替代。
```
/bin/sh test.sh
```

## shell变量
#### 定义变量
注意：
* 定义变量名的时候，变量名不加美元符号。
* 变量名和等号之间不能有空格
* 只能使用英文字母，数字和下划线，首个字符不能以数字开头
* 不能使用bash里的关键字
* 中间不能有空格，可以使用下划线
* 不能使用标点符号

```
user_name="name"
```
除了显示地直接赋值，也可以使用语句给变量赋值。
```
for file in `ls /etc`
或
for file in $(ls /etc)
```
上面语句会将/etc下目录的文件名循环出来
#### 使用变量
要使用变量的值，只要在变量名前面加美元符号即可。
```
your_name="qinjx"
echo $your_name
echo ${your_name}
```
变量名外的花括号是可选的，加上是为了帮助解释器识别变量的边界。**推荐给所有的变量都加上花括号**
```
for skill in Ada Coffe Action Java; do
    echo "I am good at ${skill}Script"
done
```
已定义的变量，可以被重新赋值，这也是脚本语言的共同特点之一。
#### 只读变量
使用readonly可以将变量定义为只读变量，只读变量的值不能被改变。
#### 删除变量
uset 可以删除变量，已删除的变量不能再次使用。uset不能删除只读变量。
```
unset variable_name
```
注意：删除变量后，变量就相当于没有定义过，而未定义过的变量是可以使用的，只是它的值为空。比如下面的脚本就没有输出。
```
#!/bin/sh
myUrl="http://www.runoob.com"
unset myUrl
echo $myUrl
```
#### 变量类型
运行shell的时候，会同时存在三种变量：
* 局部变量。局部变量在脚本或命令中定义，仅在当前shell实例中有效，其他shell启动的程序不能访问局部变量。
* 环境变量。所有的程序，包括shell启动的程序，都能访问环境变量，有些程序需要环境变量来保证其正常运行。必要的时候，shell脚本也可以定义环境变量。
* shell变量。shell变量是由shell程序设置的特殊变量。shell变量中有一部分是环境变量，一部分是局部变量。

#### shell字符串
字符串可以用单引号，也可以用双引号，也可以不用引号，单双引号的区别跟PHP一样。  
**单引号**：
* 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的
* 单引号字符串中不能出现单引号（对单引号使用转义符后也不行）  

**双引号**：
* 双引号中可以有变量
* 双引号中可以出现转义字符。 
```
your_name='qinjx'
str="Hello, I know you are \"$your_name\"! \n"
``` 
 
###### 拼接字符串：下面两句输出一样
```
your_name="qinjx"
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting $greeting_1
```
###### 获取字符串长度
```
string="abcd"
echo ${#string} #输出 4
```
###### 提取子字符串：字符串第一个字符为0位
```
string="runoob is a great site"
echo ${string:1:4} # 输出 unoo
```
###### 查找子字符串
```
string="runoob is a great company"
echo `expr index "$string" is`  # 输出 8
```
###### 字符串截取  
有八种方法，假设有变量var=http://www.aaa.com/123.htm
*
#### shell数组
bash只支持一维数组，并且没有限制数组的大小。数组元素的下标从0开始编号。
###### 定义数组
```
数组名=(值1 值2 ... 值n)
```
```
array_name=(
value0
value1
value2
value3
)
```
也可以单独定义数组的各个变量，下标可以不连续，并且下标的范围没有限制。
```
array_name[0]=value0
array_name[1]=value1
array_name[n]=valuen
```
###### 读取数组  
一般格式：
```
${数组名[下标]}
```
读取指定位置的变量
```
valuen=${array_name[n]}
```
使用@可以获取数组的所有元素
```
echo ${array_name[@]}
```
###### 获取数组的长度  
获取数组长度的方法和获取字符串长度的方法相同
```
# 取得数组元素的个数
length=${#array_name[@]}
# 或者
length=${#array_name[*]}
# 取得数组单个元素的长度
lengthn=${#array_name[n]}
```
## shell注释
shell中，以#开头的行就是注释，会被解释器忽略，sh中没有多行注释。   
如果在开发过程中，需要对一段代码临时注释，过一会儿又取消注释。可是将这一段要注释的代码用花括号括起来，定义成一个函数。没有其他地方调用，就能达到注释的效果。

