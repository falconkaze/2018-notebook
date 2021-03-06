# linux基本知识
【参考文献】  
【1】 [Ubuntu完全教程，让你成为Ubuntu高手！](https://www.jianshu.com/p/0ae245cfe1cf?utm_campaign=maleskine&utm_content=note&utm_medium=seo_notes&utm_source=recommendation)  
【2】
## 分区概念
首先：硬盘分区的存在，是由硬盘的物理特性决定的，并不会因为不同的操作系统而有所改变。  

在linux中，分区是这样表示的：
```
/dev/hda	/dev/hda1	/dev/hda2	/dev/sdb2
```
以/dev/hda5为例：  
在linux中，每一个设备都是用/dev/文件夹下的一个文件来表示的，所以/dev/hda5中，/dev/表示的是根目录下的dev目录；hda5中，hd表示这是一块IDE硬盘，如果是sd，则代表SATA硬盘，或者闪存等外设；a表示这个该类型设备的第一个设备。例如hdc表示第二个IDE接口上的主硬盘（每隔IDE接口允许一个主设备和一个从设备）；数字5并不表示这是该硬盘的第五个分区，而是指第一个逻辑分区。因为在linux中，为了避免不必要的混乱，分区的顺序是不能变的，分区标识则由它们在硬盘中的位置决定的。系统又要为所有可能的主分区预留标识，所以1-4一定不会是逻辑分区，5则是第一个逻辑分区，以此类推。（应该只是一种引导方式才是这样）  
### 挂载分区与文件系统
Windows的分区管理是将各个分区独立出来进行管理；而linux将分区与文件管理结合在一起，形成一种树状的结构，并且将系统目录的管理权限交给用户，用户可以选择将系统的不同目录挂载在不同的分区。
挂载分区就是将一个分区的入口设为一个系统中已存在的文件夹。挂载后，访问那个文件夹就等于访问挂载的分区。  
理论上，可以将分区挂载在到任何目录下。但是推荐按照linux系统的默认约定来来挂载。  
FHS，文件系统层次结构标准，它规定了linux根目录各个文件夹的名称及作用。FHS定义了两层linux下的目录作用如下：
* /根目录，唯一一个必须挂载的目录。在绝大多数情况下，有2G容量应该是够用了。建议根目录下只放目录，不要存放文件。
* Swap交换分区，不是必须的，不过按照传统，并且考虑到安全，最好挂载它。它的容量只要大于物理内存就可以了，如果超过物理内存两倍的容量，就是一种浪费。
* home，普通用户的家目录，通常用户创建的文件都在这里。最好分配一个分区，方便管理及系统恢复。
* /usr，应用程序目录，大部分的软件都安装在这里。如果计划安装很多软件，建议分配一个分区。
* /var。如果要做服务器方面的应用，可以考虑分配一个分区。
* /boot。
* bin，可执行文件，系统的可执行文件通常在这个目录下，在环境变量中设定搜索路径，就可以直接执行，不需要定位到其路径。因为linux系统会自动到环境变量设置的目录下面去扫描。
* etc，配置文件，大多数系统程序的全局配置文件保存在这个目录下，便于用户修改管理。
* lib，库文件，集中在一起，方便共享给不同程序。可以节省磁盘空间。
* share，

## 路径
路径分为绝对路径和相对路径。绝对路径的起始点为根目录/，它指向系统中的一个绝对的位置，不受其他因素影响。例如：/etc/hosts；相对路径的起始点为当前目录，它会受到当前位置的影响，与绝对路径的区别在于绝对路径的一个字符为/。在配置中，绝对路径用于独立的场合，相对路径用于经常整体移动的场合。    
远程路径的表示方法为：协议://用户名:密码@位置/路径:端口。大多数的远程路径可以使用默认端口匿名访问，所以一般不用填写用户名、密码和端口。例如：
```
http://www.ubuntu.org.cn/.../index.html
ftp://user:passwd@ftp.ubuntu.org.cn:21
```
## 文件管理系统和软件
【1】[linux下各个目录的作用和内容](https://www.cnblogs.com/sytfyf/p/6364691.html)  
linux中没有注册表这个概念。安装软件的时候，理论上讲，只要拷贝所有相关文件，并运行它的主程序就行了。按照传统，一个软件的各个部分分别安装到bin，etc，lib，share等文件夹下。  

