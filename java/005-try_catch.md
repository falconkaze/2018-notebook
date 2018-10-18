# try-catch语句

## 自动释放资源
[Java 7 try-with-resources 语句，自动资源释放,提高容错率！](https://blog.csdn.net/shasiqq/article/details/53611824)

从Java 7 build 105 版本开始，Java的编译器和运行环境支持新的`try-with-resources`语句，称为ARM块（Automatic Resource Management）。

一般情况下，在使用需要释放的资源时，代码如下：

```java
File file = null;

try{
  file = new File(path);
  ...
}finally{
  if(file != null){
    file.close();
  }
}
```

在java 7及更新版本中，可以这样写（前提是要释放的资源实现了`AuthClosable`接口）

```java
try(File file = new File(path)){
  ...
}
```
