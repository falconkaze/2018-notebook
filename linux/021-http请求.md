# linux发送http请求

## curl命令

#### 实例

* get请求

```shell
curl http://www.baidu.com
```

* post请求

```shell

```

## 一些技巧

1. 在curl响应体的末尾自动添加换行符

在`~/.curlrc`中添加

```
-w '\n'
```
