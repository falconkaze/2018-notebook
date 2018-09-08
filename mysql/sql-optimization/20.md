[MYSQL性能优化的20+建议](https://www.oschina.net/question/12_9917)
### 为使用缓存优化查询sql
大多数的mysql服务器都开启了查询缓存，这是提高性能最有效的方法之一，而且这是被mysql的数据库引擎处理的。当很多相同的查询被执行了多次的时候，这些查询结果会被放到一个缓存中，这样，后续的相同查询就会直接访问缓存结果而不会去操作表。
```
// 查询缓存不开启
$r = mysql_query("SELECT username FROM user WHERE signup_date >= CURDATE()");
  
// 开启查询缓存
$today = date("Y-m-d");
$r = mysql_query("SELECT username FROM user WHERE signup_date >= '$today'");
```
为了使用查询缓存，必须保证sql语句中参数都是明确的。
### EXPLAIN你的SELECT查询
使用EXPLAIN关键字可以让我们知道MYSQL是如何处理Sql语句的,这可以帮助我们分析查询语句或者是表格结构的性能瓶颈。
EXPLAIN的查询结果还会告诉我们索引主键式如何被利用的，数据表是如何被搜索和排序的...
### 当只要一行数据时使用LIMIT 1
当你查询表的有些时候，你已经知道结果只会有一条结果，但因为你可能需要去fetch游标，或是你也许会去检查返回的记录数。  
在这种情况下，加上LIMIT 1 可以增加性能，这样，MYSQL数据库引擎会在找到一条数据后停止搜索，而不是继续往后查找下一条符合条件的数据。如果查询条件只有主键或索引，性能应该差距不大。
### 为搜索字段建立索引
需要知道什么样的搜索可以使用索引，什么样的搜索不能使用正常的索引。
### 在Join表的时候使用相当类型的列，并将其索引
如果程序中有许多Join查询，应该确认两个表中的Join字段是建过索引的，这样，MYSQL内部会启动优化Join Sql语句的机制。  
而且，这些被用来Join的字段，应该是相同类型的。例如：如果要把DECIMAL字段和INT字段Join在一起，MYSQL就无法使用他们的索引，对于String类型，还需要有相同的字符集才行。
### 永远为每张表设置一个ID
应该为每张表设置一个ID作为主键，并且最好是int类型的（推荐使用UNSIGHED），并设置自动递增（AUTO_INCREMENT）。  
使用VARCHAR类型作为主键会使得性能下降。另外在程序中应该使用表的ID来构造数据结构。
### 使用ENUM而不是VARCHAR
ENUM 类型是非常快和紧凑的。在实际上，其保存的是 TINYINT，但其外表上显示为字符串。这样一来，用这个字段来做一些选项列表变得相当的完美。  
如果已经知道字段的取值是有限的，明确的，应该把字段设为Enum。  
MySQL中enum类型的字段不能显式设置默认值，默认为第一个值。
### 从PROCEDURE ANALYSE()获取建议
PROCEDURE ANALYSE() 会让 MySQL 帮你去分析你的字段和其实际的数据，并会给你一些有用的建议。只有表中有实际的数据，这些建议才会变得有用，因为要做一些大的决定是需要有数据作为基础的。  
例如，如果你创建了一个 INT 字段作为你的主键，然而并没有太多的数据，那么，PROCEDURE ANALYSE()会建议你把这个字段的类型改成 MEDIUMINT 。或是你使用了一个 VARCHAR 字段，因为数据不多，你可能会得到一个让你把它改成 ENUM 的建议。这些建议，都是可能因为数据不够多，所以决策做得就不够准。
### 尽可能地使用NOT_NULL
除非你有一个很特别的原因去使用 NULL 值，你应该总是让你的字段保持 NOT NULL。
>“NULL columns require additional space in the row to record whether their values are NULL. For MyISAM tables, each NULL column takes one bit extra, rounded up to the nearest byte.”    ——摘自MySQL自己的文档
