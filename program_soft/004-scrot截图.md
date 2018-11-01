# 截图软件scrot

* [scrot使用说明](http://blog.sina.com.cn/s/blog_57878a0f0101e4y2.html)
* [如何从Linux命令行截屏](https://linux.cn/article-3197-1.html)

scrot是一款命令行截图工具，支持全屏，窗口，选取，多设备，缩略图，延时，甚至可以截图完毕之后制定某程序打开截到的图片。

## 常用命令

```shell
scrot ~/abc.png  全屏截图并保存到指定位置
scrot -bs ~/abc.png 自动抓取窗口
scrot -s ~/abc.png 抓取鼠标选定区域
scrot -cd 10 ~/abc.png 延迟10秒抓取
scrot -t 20% -s ~/abc.png 生成缩略图(20%比例)
scrot -s ~/abc.png -e 'feh $f' 截图后执行某项操作，这里是用feh打开截到的图片
```
