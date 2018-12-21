# docker资源管理

* [docker限制容器的可用内存](https://www.ibm.com/developerworks/community/blogs/132cfa78-44b0-4376-85d0-d3096cd30d3f/entry/%E9%99%90%E5%88%B6%E5%AE%B9%E5%99%A8%E5%AF%B9%E5%86%85%E5%AD%98%E7%9A%84%E4%BD%BF%E7%94%A8_%E6%AF%8F%E5%A4%A95%E5%88%86%E9%92%9F%E7%8E%A9%E8%BD%AC_Docker_%E5%AE%B9%E5%99%A8%E6%8A%80%E6%9C%AF_27?lang=en)
* [查看 docker 容器使用的资源](https://www.cnblogs.com/sparkdev/p/7821376.html)

## 限制docker资源

docker run 的参数

```bash
-m --memory 设置内存限制，默认为-1，表示没有限制
--memory-swap  设置swap使用限制，默认为-1，如果设置了内存限制，没有设置swap限制，则swap限制为内存的两倍
--vm 1 启动1个内存工作线程
--vm-bytes 100M  每个线程分配100M内存
```

## 查看docker资源占用

```bash
docker stats  # 实时显示容器资源占用，每秒刷新
docker stats --no-stream # 显示当前的资源占用状态，不会刷新
docker stats contain_id contain_name # 显示指定容器的资源占用情况，可以用名字或id
```
