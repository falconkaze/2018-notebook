# 使用ss和privoxy实现翻墙

* [archlixux配置终端和firefox](https://blog.csdn.net/qq_34661580/article/details/76910525)
* [ubuntu](https://blog.csdn.net/ATYZ123/article/details/63263956)
* [免费上网服务-Baacloud](https://blog.csdn.net/qq_16477581/article/details/80804342)
* [命令行配置代理服务器](https://yevon-cn.github.io/2017/05/05/set-proxy-of-cmd.html)

## ss使用
ss又叫shadowsocks。

#### 安装ss

```shell
pacman -S shadowsocks
```

#### 配置

编辑`/etc/shadowsocks/config.json`

```json
{
  "server":"server_host",
  "server_port":7655,
  "local_address":"127.0.0.1",
  "password":"password",
  "timeout":300,
  "method":"aes-256-cfb",
  "fast_open":false,
  "workers":1,
  "prefer_ipv6":false
}
```

* `server`        服务端监听地址(IPv4或IPv6)
* `serve_port`    服务端端口，一般为443
* `local_address` 本地监听地址，缺省为127.0.0.1
* `local_port`    本地监听端口，一般为1080
* `password`      用以加密的密匙
* `timeout`       超时时间（秒）
* `method`        加密方法，默认的table是一种不安全的加密，此处首推aes-256-cfb
* `fast_open`     是否启用TCP-Fast-Open
* `workers`       worker数量，如果不理解含义请不要改

#### 启动ss服务

* 启动客户端
  
  ```shell
  sslocal -c /etc/shadowsocks/config.json
  # 或
  systemctl start shadowsocks@config
  # 开机自启动
  systemctl enable shadowsocks@config
  ```
* 启动服务器

  ```shell
  systemctl start shadowsocks-server@config
  systemctl enable shadowsocks-server@config
  ```

  注意：如果服务端的端口号小于1024，需要修改usr/lib/systemd/system/shadowsocks-server@.service使得user=root，之后使用systemctl daemon-reload重新载入守护进程配置，即可开启监听。

## 使用插件实现浏览器翻墙

  chrome浏览器使用[SwitchyOmega](https://chrome.google.com/webstore/detail/proxy-switchyomega/padekgcemlokbadohgkifijomclgjgif)将需要翻墙的域名指向ss配置的地址（127.0.0.1:1080）。

## 使用privoxy翻墙

#### 安装privoxy

  ```shell
  pacman -S privoxy
  ```

#### 配置privoxy

  配置文件位置：`/etc/privoxy/config`。需要注意两个地方：`listen-address`表示监听地址，需要将请求转发到这个接口。`forward-socks5`表示socks的代理地址（也就是ss的本地端口）

  修改`/etc/profile`，添加环境变量，这一步是配置代理地址

  ```shell
  export http_proxy="127.0.0.1:8118"
  export https_proxy="127.0.0.1:8118"
  ```

#### 启动服务

  ```shell
  systemctl start privoxy
  ```
