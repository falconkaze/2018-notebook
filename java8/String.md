# String的一些细节
##String对null对象的容错处理
[String对null对象的容错处理](https://www.cnblogs.com/a31415926/p/6740258.html)
《Thinking in Java》中有这样一段话：Primitives that are fields in a class are automatically initialized to zero, as noted in the Everything Is an Object chapter. But the object references are initialized to null, and if you try to call methods for any of them, you’ll get an exception-a runtime error. Conveniently, you can still print a null reference without throwing an exception.
* print(String str)的时候，如果String为null，打印"null"
* print(Object obj)的时候，调用String.valueOf(Object obj),valueOf方法内对null进行了判断。
* null+str的时候，编译器会调用StringBuilder的append方法，append方法中对null进行了判断。
