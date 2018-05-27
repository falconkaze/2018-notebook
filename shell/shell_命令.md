# shell命令  
【参考文献】  
【1】[linux命令大全](http://man.linuxde.net/printf)
## echo命令
shell的echo指令和PHP的echo指令类似，都是字符串的输出。
```
echo string
```

||能否引用变量|能否引用转义符|能否引用文本格式符（换行符，制表符等）|
|:-:|-|-|-|
|单引号|否|否|否|
|双引号|能|能|能|
|能|能|否|
所以：
* 如果需要按原来格式输出，使用单引号，除非字符串中有单引号
* 其他情况下尽量使用双引号
#### 参数
|参数|desc	|
|:-: |-		|
|-e	 |开启转义，\"这种不需要这个参数就可以转义|

```
echo "\"It is a test\""
echo -e "OK! \n" 				# -e开启转义
echo -e "OK! \c" 				# -e开启转义 \c 不换行
echo "It is a test" > myfile	# 将结果定向至文件
echo `date`						# 显示执行结果
```
## printf命令
printf也是一个输出命令，它模仿C语言的printf()方法。printf由POSIX标准定义，使用它的脚本比使用echo的脚本移植性好。  
printf 使用引用文本或空格分隔的参数，外面可以在 printf 中使用格式化字符串，还可以制定字符串的宽度、左右对齐方式等。默认 printf 不会像 echo 自动添加换行符，我们可以手动添加 \n。  
语法：
```
printf format-String [arguments...]
```
示例：
```
#!/bin/bash
printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg  
printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234 
printf "%-10s %-8s %-4.2f\n" 杨过 男 48.6543 
printf "%-10s %-8s %-4.2f\n" 郭芙 女 47.9876 

姓名     性别   体重kg
郭靖     男      66.12
杨过     男      48.65
郭芙     女      47.99
```
* %s	String，对应位置的参数必须为字符串或者字符型
* %d	Decimal，十进制整数
* %c	Char，字符串或者字符型。如果为字符串，会自动截取字符串的第一个字符
* %f	Float，数字型
%-10s	设置宽度为10个字符（-表示左对齐，没有则表示右对齐），若字符串为或小于10个字符宽，相当于制表符，如果超过，也会把所有内容显示出来。  
%-4.2f	指格式化小数，其中.2表示保留两位小数。  

```
#!/bin/bash
# format-string为双引号
printf "%d %s\n" 1 "abc"
# 单引号与双引号效果一样 
printf '%d %s\n' 1 "abc" 
# 没有引号也可以输出
printf %s abcdef
# 格式只指定了一个参数，但多出的参数仍然会按照该格式输出，format-string 被重用
printf %s abc def
printf "%s\n" abc def
printf "%s %s %s\n" a b c d e f g h i j
# 如果没有 arguments，那么 %s 用NULL代替，%d 用 0 代替
printf "%s and %d \n" 

1 abc
1 abc
abcdefabcdefabc
def
a b c
d e f
g h i
j  
 and 0
```
转义字符：

|转义符|desc|
|-|-|
|\a	|警告字符，通常为ASCII的BEL字符|
|\b	|后退|
|\c	|抑制（不显示）输出结果中任何结尾的换行字符（只在%b格式指示符控制下的参数字符串中有效），而且，任何留在参数里的字符、任何接下来的参数以及任何留在格式字符串中的字符，都被忽略|
|\f	|换页（formfeed）|
|\n	|换行|
|\r	|回车（Carriage return）|
|\t	|水平制表符|
|\v	|垂直制表符|
|\\\\	|一个字面上的反斜杠字符|
|\ddd	|表示1到3位数八进制值的字符。仅在格式字符串中有效|
|\0ddd	|表示1到3位的八进制值字符|
```
printf "a string, no processing:<%s>\n" "A\nB"
printf "a string, no processing:<%b>\n" "A\nB"
printf "www.runoob.com \a"

a string, no processing:<A\nB>
a string, no processing:<A
B>
www.runoob.com $                  #不换行
```
