# docker 导入导出

## 镜像导入导出

```bash
docker save image_id > name.tar
docker load < name.tar
```

## 容器导入导出

```bash
docker export contain_id > contain.tar
docker import contain.tar
```

## 区别

1. 镜像导入和容器导入的区别
  
  - 容器导入是将当前容器变成一个新的镜像

  - 镜像导入是复制的过程

2. save和export的区别

  - save保存镜像所有的信息，包含历史

  - export只导出当前的信息
