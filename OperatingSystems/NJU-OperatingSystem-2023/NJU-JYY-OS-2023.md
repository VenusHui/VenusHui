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

- 批处理系统、`DOS, Disk Operating System` 
- 集成电路、高级语言和编译器
- UNIX 及其衍生产品

通过虚拟化将硬件资源进行抽象提供给上层应用程序

## 2. 应用视角的操作系统

### 2.1 汇编代码和最小可执行文件

```c
#include <stdio.h>
int main() {
    printf("hello\n");
    return 0;
}
```

```c
#include <sys/syscall.h>

.globl _start
_start:
  movq $SYS_write, %rax   // write(
  movq $1,         %rdi   //   fd=1,
  movq $st,        %rsi   //   buf=st,
  movq $(ed - st), %rdx   //   count=ed-st
  syscall                 // );

  movq $SYS_exit,  %rax   // exit(
  movq $1,         %rdi   //   status=1
  syscall                 // );

st:
  .ascii "\033[01;31mHello, OS World\033[0m\n"
ed:
```

#### 汇编代码的状态机模型

- 状态：内存 `Memory` + 寄存器 `Registers` 
- 初始状态：`ABI, Application Binary Interface` 规定
- 状态迁移：执行一条指令

### 2.2 C 程序的形式语义

#### 理解高级语言程序状态机模型

- 状态：堆 + 栈
- 初始状态：`main` 函数的第一条语句
- 状态迁移：执行一条语句的一小步

#### 理解编译器

高级语言代码 `*.c` 通过编译器转化为汇编指令序列 `*.s` ，不同的优化级别产生不同的指令序列
$$
.s = complie(.c)
$$
**编译正确性** 

- `*.c` 执行中所有外部观测者可见的行为，必须在 `*.s` 中保持一致
- `volatile` 关键字：编译器提供的 **不可优化** 标注

