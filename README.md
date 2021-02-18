# UnxiCommand
the code collecton of Understanding Unix/Linux Programming 

### 1. 创建、重写文件
项目 | creat
------------ | -------------
目标 | 创建、重写文件
头文件 | # include <fcntl.h>
函数原型 | int fd = creat(char* filename, mode_t mode)
参数 | filename 文件名、mode 访问模式
返回值 | -1 遇到错误、 fd 成功创建

### 2. 写文件
项目 | write
------------ | -------------
目标 | 将内存中的数据写入文件
头文件 | # include <unistd.h>
函数原型 | ssize_t result = write(int fd, void* buf, size_t amt)
参数 | fd 文件描述符、 buf 内存数据、 amt 要写入的字节数
返回值 | -1 遇到错误、 num written 成功写入


**Standard I/O streams**
```
# include <stdio.h>

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
```

用户态和内核态的切换需要时间（超人变身）, 缓冲不能太小。
`# include <utmp.h>`
### 3. 改变文件当前位置
| 项目      | lseek            | 
| --------- | ------------------- | 
| 目标      | 使指针指向文件中的指定位置       | 
| 头文件      | # include <sys/type.h>、# include <unistd.h> |
| 函数原型   | off_t oldpos = lseek(int fd, off_t dist, int base) |
| 参数       |   fd   文件描述符   |
|            |   dist  移动的距离  | 
|            |   base  SEEK_SET => 文件的开始   |
|            |         SEEK_CUR => 当前位置     |
|            |         SEEK_SET => 文件结尾     |
| 返回值      |   -1 遇到错误   |
|            |   oldpos  指针变化前的位置  | 
