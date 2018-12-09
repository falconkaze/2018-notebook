# docker网络配置

* [From inside of a Docker container, how do I connect to the localhost of the machine?](https://stackoverflow.com/questions/24319662/from-inside-of-a-docker-container-how-do-i-connect-to-the-localhost-of-the-mach)
* [Docker容器内连接宿主机的Mysql服务器](https://www.jianshu.com/p/3e1fd311ba87)
* [Neworking fetures in Docker for Mac](https://docs.docker.com/docker-for-mac/networking/)

## mac docker的坑

首先，在mac下，docker的`--net=host`是没有效果的，可以将本地hosts文件映射给docker来替代。

其次，在linux下，使用主机虚拟网卡docker0所代表的ip（例如172.17.0.1）可以访问到本地的数据库，而mac中没有docker0这个网卡。在mac的docker中`host.docker.internal`这个地址代表主机的地址。

mac下的docker不能通过ip访问，换句话说如果需要本地访问docker服务，必须把docker的端口映射给主机。
