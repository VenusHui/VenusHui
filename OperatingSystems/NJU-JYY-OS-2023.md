# 操作系统：设计与实现

> 南京大学 2023 Spring
>
> 讲师：蒋炎岩
>
> 课程网站：https://jyywiki.cn/OS/2023/

## 1. 操作系统概述

学习任何东西的目的

- 重走 **从无到有** 的
- 学习其 **现代方法** 

### 1.1 为什么要学习操作系统

- 每天都在用的东西，还没搞明白
- 每天都在用的东西，实现不出来

### 1.2 什么是操作系统

> A software; Make it easy to run programs; Allow programs to share memory

#### 硬件

- 数字逻辑电路
- 建立在公理体系上的数字系统设计

#### 软件

- 高级语言代码
- 指令序列
- 二进制文件
- 处理器执行

#### 操作系统

- 批处理系统、Disk Operating System (DOS) 
- 集成电路、高级语言和编译器
- UNIX 及其衍生产品

通过虚拟化将硬件资源进行抽象提供给上层应用程序

## 2. 应用视角的操作系统

### 2.1 汇编代码和最小可执行文件

```c
#include <stdio.h>
int main() {
    printf("helllo\n");
    return 0;
}
```



