# java doc 书写

使用javadoc的方式主要由两种：嵌入HTML，或者使用“文档标签”。独立文档标签指一些以“@”开头的命令，且要置于注释行的最前面（`*`后面）。而行内文档标签可以出现在文档的任何地方，也是以“@”开头的，但是需要放在大括号内。

javadoc只能为public或者protected成员进行文档注释。这是因为对用户暴露出去的只有public和protected变量。

注意不要在嵌入式HTML中使用标题标签，因为javadoc会自己生成标题，手动插入的标题会与之冲突。

## 标签示例

1. @see 引用其他类或成员

2. {@link }

3. {@dataRoot}

4. {@inheritDoc}

5. @version

6. @author

7. @since

8. @param

9. @return

10. @throws

11. @Deprecated
