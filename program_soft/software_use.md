# linux常用软件及使用

## 图像查看——feh
【参考资料】  
【1】 [Feh——archlinux](https://wiki.archlinux.org/index.php/Feh)

## redshift

配置~/.config/redshift.conf
```
[redshift]
; 白天屏幕温度
temp-day=5000
; 夜晚屏幕温度
temp-night=4100
; 昼夜是否平滑过度(1/0)
transition=1

; 位置提供方式(redshift -l list)
location-provider=manual

[manual]
; 位置提供方式设置
; 经纬度(北京)
lat=39.90
lon=116.41
```
