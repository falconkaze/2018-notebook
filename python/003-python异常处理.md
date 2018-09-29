# python异常处理

## try...except

```python
try:
    text = input('Enter something --> ')
except EOFError:
    print('Why did you do an EOF on me?')
except KeyboardInterrupt as ex:
    print('You cancelled the operation.')
else:
    print('You entered {}'.format(text))
```

`except`语句如果没有指定错误或异常的名字，将处理所有的错误与异常。`else`语句在没有发生异常的时候执行。

`raise`语句用来抛出异常（可以抛出的异常必须是直接或间接从属于`Exception`类）

```python
raise Exception()
```

## try...finally

类似于java，多用与释放资源。

```python
try:
    f = open("poem.txt")
finally:
    if f:
        f.close()
```

## with语句

`with`语句是`try...finally`的一种简化，用于释放资源。在java中也有类似的语句（具体不记得了）。

```python
with open("poem.txt") as f:
    for line in f:
        print(line, end='')
```


