# mysql数据类型

## 字符串

mysql中的字符类型主要有以下几种：

| 数据类型      | 含义                         |
| ------------- | ---------------------------- |
| char(n)       | 固定长度，最多2^8 -1个字节   |
| varchar((n)   | 可变长度，最多2^16 - 1个字节 |
| tinytext(n)   | 可变长度，最多2^8 - 1个字节  |
| text(n)       | 可变长度，最多2^16 - 1个字节 |
| mediumtext(n) | 可变长度，最多^24 - 1个字节  |
| longtext(n)   | 可变长度，最多^32 -1 个字节  |

mysql中，char(n)和varchar(n)中n表示能储存的字符数，而不是字节数，比如存放10个汉字，就相当于占用30个字节。

char和varchar很相似，但是在存储方式和检索方式，以及最大长度和尾部的空格的处理方式上有区别。

* 长度方面

  char的长度是固定的，长度（字节长度）范围为0 - 255。当char值储存时，会在右侧补上空格，使得字符的长度为指定的长度。当char值检索的时候，尾部的空格会被移除（包括本来就带有的空格），除非指定了```PAD_CHAR_TO_FULL_LENETH```模式。

  varchar的长度是可变的，长度（字节长度）范围为0 - 65535。不会自动填补空格，并且在插入和检索时空格都会保留。注意：这个范围是所有的varchar列共享的。如果总和超出的话，需要将部分修改为text类型。相比于char，varchar保存的数据前有一或两个字节来表示数据的字节数，小于255时用一个字节来表示，这两个字节不在括号的限制内，但在字符空间的限制内。
  下面这个建表语句就会报错，因为varchar总长度超过了65535。
  ```mysql
  CREATE TABLE t (a VARCHAR(10000), b VARCHAR(10000),
  c VARCHAR(10000), d VARCHAR(10000), e VARCHAR(10000),
  f VARCHAR(10000), g VARCHAR(6000)) ENGINE=InnoDB
  ```

* 当插入字符长度超出限制，且超出部分全为空格的时候。char和varchar会自动删掉多于的空格，区别在于varchar会生成警告信息，而char不会。

* 当插入字符长度超出限制，并且超出部分不是空格的时候，char和varchar都会截断多于的字符。当处于严格模式下（strict），mysql会拒绝插入长度过长的字符，并抛出错误。

* char和varchar列中的值都根据分配给列的字符集排序规则进行排序和比较。

InnoDB encodes fixed-length fields greater than or equal to 768 bytes in length as variable-length fields, which can be stored off-page. For example, a CHAR(255) column can exceed 768 bytes if the maximum byte length of the character set is greater than 3, as it is with utf8mb4.

Most MySQL collations have a pad attribute of PAD SPACE. The exceptions are Unicode collations based on UCA 9.0.0 and higher, which have a pad attribute of NO PAD. (see Section 10.10.1, “Unicode Character Sets”).

To determine the pad attribute for a collation, use the INFORMATION_SCHEMA COLLATIONS table, which has a PAD_ATTRIBUTE column.

The pad attribute determines how trailing spaces are treated for comparison of nonbinary strings (CHAR, VARCHAR, and TEXT values). NO PAD collations treat spaces at the end of strings like any other character. For PAD SPACE collations, trailing spaces are insignificant in comparisons; strings are compared without regard to any trailing spaces. “Comparison” in this context does not include the LIKE pattern-matching operator, for which trailing spaces are significant. For example:

基于这一点，带有unique index的列不能同时存在"a"和"a "

```
mysql> CREATE TABLE names (myname CHAR(10));
Query OK, 0 rows affected (0.03 sec)

mysql> INSERT INTO names VALUES ('Monty');
Query OK, 1 row affected (0.00 sec)

mysql> SELECT myname = 'Monty', myname = 'Monty  ' FROM names;
+------------------+--------------------+
| myname = 'Monty' | myname = 'Monty  ' |
+------------------+--------------------+
|                1 |                  1 |
+------------------+--------------------+
1 row in set (0.00 sec)

mysql> SELECT myname LIKE 'Monty', myname LIKE 'Monty  ' FROM names;
+---------------------+-----------------------+
| myname LIKE 'Monty' | myname LIKE 'Monty  ' |
+---------------------+-----------------------+
|                   1 |                     0 |
+---------------------+-----------------------+
1 row in set (0.00 sec)
```
