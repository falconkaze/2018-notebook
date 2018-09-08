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
expr length "$string" #输出为4
```
###### 字符串截取  
#、##表示从左边开始删除。一个#表示从左边删除到第一个指定的字符，两个#表示从左边删除到最后一个指定的字符。  
%、%%表示从右边开始删除。一个%表示从右边删除到第一个指定的字符，两个%表示从左边删除到最后一个指定的字符。  
删除包括了指定的字符本身。
```
var=http://www.aaa.com/123.htm
echo ${var#*//}		#www.aaa.com/123.htm
echo ${var##*/}		#123.htm
echo ${var%/*}		#http://www.aaa.com
echo ${var%%/*}		#http:
#从左边第一个字符开始，截取5个字符
echo ${var:0:5}		#http:
#从左边第七个字符开始，直到结束
echo ${var:7}		#www.aaa.com/123.htm
#从右边第七个字符开始，截取3个字符（从左到右截取）
echo ${var:0-7:3}	#123
#从右边地七个字符开始，直到结束
echo ${var:0-7}		#123.htm
```
###### 查找子字符串
```
string="runoob is a great company"
echo `expr index "$string" is`  # 输出 8
```
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
使用@或*可以获取数组的所有元素
```
echo ${array_name[@]}
echo ${array_name[*]}
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
## shell传递参数  
我们在执行shell脚本的时候，可以向脚本传递参数，脚本中获取参数的格式为：$n。n表示第几个参数，0表示执行脚本的文件名。  
在为shell脚本传递的参数中如果有空额，应该用单引号或者双引号将该参数括起来，以便脚本将这个参数作为一个整体来读取。  

|符号|desc|
|:--|:--|
|$n|获取第几个参数，0为文件名|
|$#|传递给脚本的参数个数|
|$*|以一个字符串显示所有向脚本传递的函数，形式："$1 $2 $3"|
|$$|脚本运行的当前进程ID|
|$!|后台运行的最后一个进程的ID号|
|$@|与$*类似，但是使用时会给每个变量加上引号,形式："$1" "$2" "$3"|
|$-|显示shell使用的当前选项。与set命令功能相同。|
|$?|显示最后命令的退出状态，0表示没有错误，其他任何值表示有错误。|
```
#!/bin/bash
echo "Shell 传递参数实例！";
echo "执行的文件名：$0";
echo "第一个参数为：$1";
echo "参数个数为：$#";
echo "传递的参数作为一个字符串显示：$*";

$ chmod +x test.sh 
$ ./test.sh 1 2 3
Shell 传递参数实例！
执行的文件名：./test.sh
第一个参数为：1
参数个数为：3
传递的参数作为一个字符串显示：1 2 3
```
$* 与 $@ 区别：
* 相同点：都是引用所有参数。
* 不同点：只有在双引号中体现出来。假设在脚本运行时写了三个参数 1、2、3，，则 " * " 等价于 "1 2 3"（传递了一个参数），而 "@" 等价于 "1" "2" "3"（传递了三个参数）。

```
#!/bin/bash
echo "-- \$* 演示 ---"
for i in "$*"; do
    echo $i
done
echo "-- \$@ 演示 ---"
for i in "$@"; do
    echo $i
done

$ chmod +x test.sh 
$ ./test.sh 1 2 3
-- $* 演示 ---
1 2 3
-- $@ 演示 ---
1
2
3
```
在需要传递参数的时候，最好对参数进行校验，减少错误的发生。
```
if [ -n "$1" ]; then
    echo "包含第一个参数"
else
    echo "没有包含第一参数"
fi
```
**注意**：中括号 [] 与其中间的代码应该有空格隔开
## shell基本运算符
shell也支持多种运算符：算数运算符、关系运算符、布尔运算符、字符串运算符、文字测试运算符。  
#### 算数运算符
原生bash不支持简单的数字运算，但是可以通过其他命令来实现。例如awk和expr，后者更常用。  
expr是一款表达式计算工具，使用它能完成表达式的求值操作。  
**注意**：
* 表达式和运算符之间要有空格
* 完整的表达式要被``包含  
* 乘号(*)前必须加反斜杠(\)才能实现乘法运算
* 在mac中，shell的expr的语法是：$((表达式))，这里表达式中的*不需要转义符\  

|运算符|说明|举例		  			|
|-	   |-	|-						|
|+	   |加法|\`expr $a + $b\` 		|
|-	   |减法|\`expr $a - $b\` 		|
|*	   |乘法|\`expr $a \* $b\` 		|
|/	   |除法|\`expr $b / $a\` 		|
|%	   |取余|\`expr $b % $a\` 		|
|=	   |赋值|a=$b 将把变量b的值赋给a|
#### 关系运算符
关系运算符只支持数字，不支持字符串，除非字符串的值是数字。
shell中的关系运算符有： == 、 != 、 -eq 、 -ne 、 -gt 、 -lt 、 -ge 、 -le 。后面几个表示equal、not equal、greater than、less than、greater than or equal、less than or equal。  
**注意**
* 条件表达式要放在方括号中，并且要有空格
* 运算符两边也要有空格
```
[ $a == $b ]
```
进行数值比较时，可以使用 [ expression1 OP expression2 ]，OP 可以为 -gt、-lt、-ge、-le、-eq、-ne 也可以使用 ((expression1 OP expression2))，OP 可以为 >、<、>=、<=、==、!=。
#### 布尔运算符
shell中的布尔运算符： ! 、 -o 、 -a 。分别表示no、or、and。  
```
[ $a -lt 100 -a $b -gt 15 ]
```
#### 逻辑运算符
|| && 分别表示逻辑或和逻辑与。
```
[[ $a -lt 100 && $b -gt 100 ]]
```
使用 [[ ... ]] 条件判断结构，而不是 [ ... ]，能够防止脚本中的许多逻辑错误。比如，&&、||、< 和 > 操作符能够正常存在于 [[ ]] 条件判断结构中，但是如果出现在 [ ] 结构中的话，会报错。

#### 字符串运算符
假设a='abc'，b='efg'

|运算符	|desc				|举例					|
|:-:   	|-					|-						|
|=	   	|相等为true			|[ $a = $b ]返回false。	|
|!=		|不等为true 		|[ $a != $b ] 返回true。|	
|-z		|长度为0为true		|[ -z $a ] 返回 false。	|
|-n		|长度不为0为true	|[ -n $a ] 返回 true。	|
|str	|字符串为空返回true	|[ $a ] 返回 true。		|
* \>、<、==、!= 也可以进行字符串比较。
* 进行字符串比较时，== 可以使用 = 替代。
* == 和 !=进行字符串比较时，可以使用 [ string1 OP string2 ] 或者 [[ string1 OP string2 ]] 的形式。
* \> 和 < 进行字符串比较时，需要使用[[ string1 OP string2 ]] 或者 [ string1 \OP string2 ]。也就是使用 [] 时，> 和 < 需要使用反斜线转义。
#### 文件测试运算符
文字测试运算符用来检测Unix文件的各种属性。

操作符	说明	举例
-b file	检测文件是否是块设备文件，如果是，则返回 true。	[ -b $file ] 返回 false。
-c file	检测文件是否是字符设备文件，如果是，则返回 true。	[ -c $file ] 返回 false。
-d file	检测文件是否是目录，如果是，则返回 true。	[ -d $file ] 返回 false。
-f file	检测文件是否是普通文件（既不是目录，也不是设备文件），如果是，则返回 true。	[ -f $file ] 返回 true。
-g file	检测文件是否设置了 SGID 位，如果是，则返回 true。	[ -g $file ] 返回 false。
-k file	检测文件是否设置了粘着位(Sticky Bit)，如果是，则返回 true。	[ -k $file ] 返回 false。
-p file	检测文件是否是有名管道，如果是，则返回 true。	[ -p $file ] 返回 false。
-u file	检测文件是否设置了 SUID 位，如果是，则返回 true。	[ -u $file ] 返回 false。
-r file	检测文件是否可读，如果是，则返回 true。	[ -r $file ] 返回 true。
-w file	检测文件是否可写，如果是，则返回 true。	[ -w $file ] 返回 true。
-x file	检测文件是否可执行，如果是，则返回 true。	[ -x $file ] 返回 true。
-s file	检测文件是否为空（文件大小是否大于0），不为空返回 true。	[ -s $file ] 返回 true。
-e file	检测文件（包括目录）是否存在，如果是，则返回 true。	[ -e $file ] 返回 true。
```
#!/bin/bash

file="/var/www/runoob/test.sh"
if [ -r $file ]
then
   echo "文件可读"
else
   echo "文件不可读"
fi
if [ -w $file ]
then
   echo "文件可写"
else
   echo "文件不可写"
fi
if [ -x $file ]
then
   echo "文件可执行"
else
   echo "文件不可执行"
fi
if [ -f $file ]
then
   echo "文件为普通文件"
else
   echo "文件为特殊文件"
fi
if [ -d $file ]
then
   echo "文件是个目录"
else
   echo "文件不是个目录"
fi
if [ -s $file ]
then
   echo "文件不为空"
else
   echo "文件为空"
fi
if [ -e $file ]
then
   echo "文件存在"
else
   echo "文件不存在"
fi
```

