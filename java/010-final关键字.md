# java final 关键字

* [深入理解Java中的final关键字](http://www.importnew.com/7553.html)
* [在编译期可直接替换的final变量](https://www.cnblogs.com/sister/p/4706024.html)

java中的final关键字可以声明成员变量，方法，类以及本地变量。

## 作用于变量

一旦把变量声明为final类型，就不能再改变这个值了，编译器会检查代码，如果试图将变量再次初始化，就会报错。

注意：将基本类型变量设为final类型，变量的值在初始化之后就不能再改变了。将对象引用设为final类型，指的是这个变量代表的引用的值不能变，也就是说不能再指向其他对象了，而不是说所指向的对象不可变。

## 作用于方法

方法前面加上final关键字，代表这个方法不能再被子类的方法重写。如果认为一个方法的功能已经足够完整了，子类中不需要修改的话，可以声明为final方法。final方法比非final方法快，因为在编译时已经静态绑定了，不需要在运行时再动态绑定。

## 作用于类

用final修饰的类不可被继承。一般类声明为final，说明功能已经完整实现了，不需要子类来扩展。

与final类相关的有个概念叫不可变类。不可变类是指它的对象一旦构造出来，就不会再改变了。String及八大基本类型的包装类都是不可变类。不可变类有很多好处，它们是只读的，可以在多线程的情况下安全地共享。不可变类的特点是成员变量全部为私有变量，并且没有暴露在外的方法可以修改它们，如果需要返回成员变量，必须进行深拷贝。实际上并不需要一定是final类型，但是如果不可变类允许被继承的话，那么在父类变量调用子类对象的时候会造成误解，认为对象不可变，而实际上子类对象可能是会变化的。

## final关键字的好处

1. final关键字提高了性能，JVM和java应用都会缓存final变量

2. final类型的不可变类可以安全在多线程环境下进行共享，而不需要额外的同步开销。

3. 使用final关键字，JVM会对方法，变量及类进行优化。

## 在编译期间可直接替换的final变量

#### 满足下面三个条件，变量就会变为一个直接量

1. 使用final修饰符修饰

2. 在声明的时候进行初始化

3. 初始化的值在编译期间就可以确定

实例如下

```java
public class Test {

  public static void main(String[] args){
    final String str1 = "final" + "field";
    final String str2 = "java8";
    final String str3 = "java" + 8;
    final String str4 = "java8" + 8;

    final String str5 = "java" + String.valueOf(8);
    final int a = 2 +3;
    final double b = 1.5 / 2;

    System.out.println("java8" == str2);
    System.out.println("java8" == str3);
    System.out.println("java88" == str4);
    System.out.println("java8" == str5);
  }

}
```

使用jad命令对编译出的class文件进行反编译，结果如下：

```java
import java.io.PrintStream;

public class Test
{

    public Test()
    {
    }

    public static void main(String args[])
    {
        String s = (new StringBuilder()).append("java").append(String.valueOf(8)).toString();
        System.out.println(true);
        System.out.println(true);
        System.out.println(true);
        System.out.println("java8" == s);
    }
}
```

我们可以发现，除了str5之外，其他的变量都在编译期件可以确定，编译器直接对这些变量求值替换，提高程序的运行效率。这就是大型程序编译速度很慢的原因，编译器不仅需要校验程序语法，把源程序编译为字节码，还需要对它们进行优化。

前三个输出为true，这是因为编译期对string进行了优化。string有个常量池的概念，对于编译期间就可以确定的string常量，java会把它们放入常量池，对于之前已经声明过的string直接量，编译期会直接把常量池中的对象地址赋值给string变量，这就导致了实例中的str1，str2，str3和"java8"为同一个对象，它们的地址是一样的。基于这个原因，在声明字符串常量的时候，最好使用`+`，不要使用concat等方法。

常量池是专门用于管理在编译期就确定并被保存在已编译的class文件中的一些数据，包括关于类，方法，接口中的常量，还包括字符串常量。

## final相关知识点

1. final关键字可作用于成员对象，本地变量，方法和类

2. final成员变量必须在声明的时候初始化或者在构造器中初始化，否则就会报编译错误

3. final变量不能被再次赋值，final方法不能被重写，final类不能被继承

4. 在匿名类中所有变量都必须是final变量

5. 接口中声明的所有变量都是final的

6. final和abstract这两个关键字是对立的，final类或方法不可能是abstract的

7. final方法在编译阶段绑定，称为静态绑定（static binding）

8. 没有在声明时初始化的final变量称为空白变量，它们必须在构造器中初始化，或者调用this()初始化，不然编译器会报错

9. 将类，方法，变量声明为final能够提高性能，这样JVM就有机会进行估计，然后优化

10. 按照java代码惯例，final变量一般是常量，通常常量名需要大写。

11. 按照惯例，即使static又是final的变量使用大写来表示，下划线隔开。

12. java允许在参数列表中以声明的方法将参数指明为final，保证参数只读，不可被改变（参数为对象时，指的是对象引用不可变）。这一特性主要用来向匿名内部类传递数据，另外，给方法传递对象来保存结果的时候可以保证操作的都是原来的对象，避免中途失误将对象参数覆盖掉。

13. 类中所有的private方法都隐式地指定为final的。因为外部类无法访问到private方法，也就无法重写它。可以对private方法添加final关键字，但是这不能给该方法增加额外的意义。子类中可以出现和父类private方法名字相同的方法，即使父类private方法指定了final也一样，但是这不是重写，只是形式类似而已。重写的表现是多态，也就是父类引用调用到的方法依赖于引用指向的子类对象，因为private方法无法被访问，也就无所谓多态了。

14. 由于final类禁止继承，所以final类的所有方法都隐式指定为final，无法覆盖它们。
