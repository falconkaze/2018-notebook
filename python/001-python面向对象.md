# python面向对象

## 继承

#### 语法

```python
class SchoolMember:
  def __init__(self, name, age):
    self.name = name
    self.age = age

class Teacher(SchoolMember):
  def __init__(self, name, age, salaxy):
    self.name = name
    self.age = age
    self.salaxy = salaxy
```

#### 规则

* 要使用继承，在定义类的时候需要在类后面跟一个包含父类名字的元组。
* 在使用子类的构造函数的时候，python不会自动调用父类的构造函数，必须显式地调用，不然不能初始化父类参数（？？）。这点和java不同，要注意区分。如果没有在子类中定义`__init__`方法，python就会自动调用父类的构造函数。
