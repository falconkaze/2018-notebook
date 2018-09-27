# mybtatis——xml配置文件
## resultType和resultMap
* resultType多用于mysql和java有直接对应关系的数据类型。对于自定义类，如果字段名和数据库表的字段名对应，也可以实现映射。  
* resultMap多用于自定义类型，实现数据库表与java类型的对应。猜测内部是使用sql的as关键字来映射。

## foreach属性
参考资料:[Mybatis foreach 批量操作](https://blog.csdn.net/jason5186/article/details/40896043)

| 属性       | 描述                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ---        | ---                                                                                                                                                                                                                                                                                                                                                                                                                                |
| item       | 必选参数。命名循环体中的具体对象，支持属性的dian路径访问。如:item.age。在list和数组中指其中的对象，在map中指value。                                                                                                                                                                                                                                                                                                                |
| collection | 必选参数。指代foreach的对象。作为入参时，List<?>默认用list代替，数组用array，Map用map。当然在作为入参时可以使用@Param("keyName")来设置键，设置keyName后，list,array,map将会失效。 除了入参这种情况外，还有一种作为参数对象的某个字段的时候。举个例子：(1)如果User有属性List ids。入参是User对象，那么这个collection = "ids"(2)如果User有属性Ids ids;其中Ids是个对象，Ids有个属性List id;入参是User对象，那么collection = "ids.id" |
| separator  | 可选参数。元素之间的分隔符，相当于mybatis自动帮助我们拼接sql。                                                                                                                                                                                                                                                                                                                                                                     |
| open       | 可选参数。foreach的开始符号，用于拼接sql。常用在in()，values()时。                                                                                                                                                                                                                                                                                                                                                                 |
| close      | 可选参数。foreach的关闭符号，用于拼接sql。                                                                                                                                                                                                                                                                                                                                                                                         |
| index      | 可选参数。在list和数组中，index是元素的序号；在map中，inde是元素的key。                                                                                                                                                                                                                                                                                                                                                            |

示例：
* 查询语句：
```
<select id="ListByIdList">
	SELECT 
		`id`,`name`,`sex`
	FROM user
	WHERE `id` IN
	<foreach collection="idList" item="id" separator="," open="(" close=")">
		#{id}
	</foreach>
</select>
```
* 插入语句
```
<insert id="saveList">
	INSERT INTO user
		(`id`,`name`,`sex`)
	VALUES
	<foreach collection="userList" item="user" separator=",">
		(#{user.id},#{user.name},#{user.sex})
	</foreach>
</insert>
```
* **注意**：foreach的作用是遍历集合拼接sql，所以语法要符合sql语法。

## $和#的区别
$的参数直接输出（不能避免sql注入问题），#的参数会被替换成?，然后传入参数值执行，应该类似与Statement和PreparedStatement的区别。

## 转义符

| 转义符   | 代表符号 | 描述    |
| ---      | ---      | ---     |
| `&lt;`   | >        | 小于号< |
| `&gt;`   | >        | 大于号> |
| `&amp;`  | &        | 和&     |
| `&qpos;` | '        | 单引号  |
| `&quot;` | "        | 双引号  |

如果有大量字符需要转义的话，可以使用```<![CDATA[ ]]>```，这是xml的语法，在CDATA中的所有内容都会被解析器忽略。

## trim标签

trim标签有四个属性：prefix，prefixOverrides，suffix，suffixOverrides。
