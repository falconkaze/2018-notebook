
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

poem = '''\
Programming is fun
When the work is done
if you wanna make your work also fun:
    use Python!
'''

# 打开文件编辑（'w'riting）
file = open("poem.txt", "w")
file.write(poem)
file.newlines
file.writelines("haha")
file.close

# 如果没有特别指定，将启动默认的阅读模式
file = open('poem.txt')
while True:
    line = file.readline()
    if len(line) == 0:
        break
    print(line,end='')
file.close()
