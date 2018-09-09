# linux shell 获取毫秒级的时间戳

在linux Shell中并没有毫秒级的时间单位，只有秒和纳秒其实这样就足够了，因为纳秒的单位范围是（000000000..999999999），所以从纳秒也是可以的到毫秒的。
```
current=`date "+%Y-%m-%d %H:%M:%S"`     #获取当前时间，例：2015-03-11 12:33:41
timeStamp=`date -d "$current" +%s`      #将current转换为时间戳，精确到秒
currentTimeStamp=$((timeStamp*1000+`date "+%N"`/1000000)) #将current转换为时间戳，精确到毫秒
echo $currentTimeStamp
```
