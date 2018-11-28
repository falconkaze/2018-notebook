# void指针

对于void指针，GNU认为`void *`和`char *`一样，所以下面写法是正确的：

```C
desc = malloc(200 * sizeof(char));
```

但是按照ANSI标准，需要对void指针进行强制转换，另外，不能对void指针进行算法操作，这是因为它坚持：进行算数运算的指针必须确定知道其所指向数据类型大小的。

```C
desc = (char *)malloc(200 * sizeof(char));
```
