# C语言typedef

C语言的typedef关键字用来给类型取一个新的名字。定义的名字推荐用大写，标识这个名字是用户定义的数据类型。

```C
// 定义了下面这个类型后，可以用BYTE来代表unsigned char
typedef unsigned char BYTE;
```

typedef 也可用于结构体

```C
typedef struct Books {
  char title[50];
  char author[50];
  int book_id;
} Book;

Book book;
```

typedef 可以为复杂的的声明定义一个简单的别名。这在回调函数中特别好用。
1. typedef 为数组取别名
  ```C
  typedef int A[6];
  A a;   // 相当于int a[6];
  ```
2. 原声明：`int *(*a[5])(int, char*)`;
```C
typdef int *(*pFun)(int, char*);
// 原声明简化后
pfun a[5];
```

3. 原声明：`void (*b[10]) (void (*)());`
```C
typedef void(*pFunParam)();
typedef void (*pFunx)(pFunParam);
// 原声明简化后
pFunx b[10];
```

## typedef 和 #define 区别

`#Define`是C指令，用于为各种数据类型定义别名，与 typedef 类似，但是它们有以下几点不同：

* typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
* typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的(在预编译的时候替换掉代码中的宏)。typedef 其实也是替换，但是比#define要彻底。
* #define可以使用其他类型说明符对宏类型名进行扩展，但对 typedef 所定义的类型名却不能这样做。
```c
#define INTERGE int
unsigned INTERGE n;  //没问题
typedef int INTERGE;
unsigned INTERGE n;  //错误，不能在 INTERGE 前面添加 unsigned
```
* 在连续定义几个变量的时候，typedef 能够保证定义的所有变量均为同一类型，而 #define 则无法保证。例如：
```c
#define PTR_INT int *
PTR_INT p1, p2;        //p1、p2 类型不相同，宏展开后变为int *p1, p2;
typedef int * PTR_INT
PTR_INT p1, p2;        //p1、p2 类型相同，它们都是指向 int 类型的指针。
```

注意：typedef 在语法上是一个存储类的关键字（如auto， extern， mutable， static， register一样），虽然它并不真正影响对象的存储特性。
```C
typedef static int INT2;   // 编译失败，“指定了一个以上的存储类”
```
