# 操作系统：设计与实现

> 南京大学 2023 Spring
>
> 讲师：蒋炎岩
>
> 课程网站：https://jyywiki.cn/OS/2023/
>
> 
>
> 计算机系统里没有魔法
>
> 计算机系统公理：你想到的就一定有人做到
>
> Talk is cheap. Show me the code. ——Linus Torvalds
>
> 把复杂的东西分解成简单的东西
>
> 机器永远是对的
>
> 任何机械的思维活动都可以用计算机替代，AI 还可以替代启发式/经验式的决策

[TOC]

##  1. 操作系统概述

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

`hello.c` 

```c
// hello.c
#include <stdio.h>
int main() {
    printf("hello\n");
    return 0;
}
```

通过一下步骤可以将一个 `.c` 文件最终编译为一个可执行文件

```shell
gcc -E hello.c -o hello.i
gcc -S hello.i -o hello.s
gcc -c hello.s -o hello.o
gcc hello.o -o hello
```

- `-E` : stop after the preprocessing stage, the output is in the form of the preprocessing source code. 
- `-S` : stop after the compilation proper, the output is in the form of an assembler source code file.
- `-c` : compile or assembler the source files, but do not link, the output is the form of an object file.

`minimal.S` 

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

### 2.4 操作系统上的应用程序

> 系统调用的序列

`strace` 非常重要的命令行工具，帮助我们观测应用程序和操作系统的边界

应用程序与操作系统沟通的唯一方式是系统调用指令，如 `x86-64` 的 `syscall` 

## 3. 硬件视角的操作系统

### 3.1 CPU 复位与固件

#### 计算机硬件的状态机模型

> 程序是严格的数学对象
>
> 不仅是程序，整个计算机系统也是一个状态机

- 状态：内存和寄存器数值
- 初始状态：手册规定 `CPU Reset` 
- 状态迁移：
  - 任意选择一个处理器
  - 响应处理器外部中断
  - 从程序计数器去指令执行

#### 硬件与程序员的约定

以 `x86-64` 系统为例，手册 [Intel® 64 and IA-32 Architectures Software Developer Manuals](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html) 规定了 CPU 的初始状态，厂商只需要将需要执行的代码放在初始状态所对应的地址上，即可在 CPU 启动后进行执行

**`Firmware`** 

- 管理、配置硬件
- 加载操作系统
- `BIOS, Basic I/O System` 
  - 提供机制，将程序员的代码载入内存
  - `Legacy BIOS` 将第一个可引导设备的第一个 512 字节加载到物理内存的 `0x7c00` 的位置，此时处理器应处于 `16-bit` 模式
- `UEFI, Unified Extensible Firmware Interface` 

### 3.2 调试 MBR 代码

> Master Boot Record 主引导记录

`mbr.S` 

```assembly
# mbr.S
#define SECT_SIZE  512

.code16  // 16-bit assembly

// Entry of the code
.globl _start
_start:
  lea   (msg), %si   // R[si] = &msg;

again:
  movb  (%si), %al   // R[al] = *R[si]; <--+
  incw  %si          // R[si]++;           |
  orb   %al, %al     // if (!R[al])        |
  jz    done         //   goto done; --+   |
  movb  $0x0e, %ah   // R[ah] = 0x0e;  |   |
  movb  $0x00, %bh   // R[bh] = 0x00;  |   |
  int   $0x10        // bios_call();   |   |
  jmp   again        // goto again; ---+---+
                     //                |
done:                //                |
  jmp   .            // goto done; <---+

// Data: const char msg[] = "...";
msg:
  .asciz "This is a baby step towards operating systems!\r\n"

// Magic number for bootable device
.org SECT_SIZE - 2
.byte 0x55, 0xAA
```

`makefile` 

```makefile
mbr.img: mbr.S
	gcc -ggdb -c $<
	ld mbr.o -Ttext 0x7c00 # load the code into 0x7c00
	objcopy -S -O binary -j .text a.out $@

run: mbr.img
	qemu-system-x86_64 -nographic $<

debug: mbr.img
	qemu-system-x86_64 -s -S -nographic $< &  # Run QEMU in background
	gdb -x init.gdb  # RTFM: gdb (1)

clean:
	rm -f *.img *.o a.out
```

`init.gdb` 

```
# Kill process (QEMU) on gdb exits
define hook-quit
  kill
end

# Connect to remote
target remote localhost:1234
file a.out
break *0x7c00
layout src
continue
```

### 3.3 编译运行操作系统内核

> 实验环境：[Abstract Machine](https://github.com/NJU-ProjectN/abstract-machine) from NJU

`hello.c` 

```c
#include <am.h>

#define ESC "\033["
#define RED ESC "01;31m"
#define CLR ESC "0m"

const char *MESSAGE = RED "Hello, OS World\n" CLR;

int main() {
  for (const char *s = MESSAGE; *s; s++) {
    putch(*s);  // Prints to platform-dependent debug console
  }
}
```

`makefile` 

```makefile
NAME := hello
SRCS := hello.c
export ARCH := x86_64-qemu

include $(AM_HOME)/Makefile
```

## 4. Python 实现操作系统模型

### 4.1 操作系统里的状态机

> 操作系统时管理多个状态机的工具

### 4.2 50 行建模操作系统

借助 python 的语言机制，通过 `yeild` 关键字暂时封存一个函数的状态

```python
def numbers():
		i = 0
    while True
    		ret = yield f'{i:b}'
      	i += ret
```

### 4.3 500 行建模操作系统

建模的意义：将状态机的执行 **画出来** 

## 5. 多处理器编程：从入门到放弃

> 线程库、现代处理器架构、宽松内存模型

操作系统作为 **状态机的管理者** ，引入了共享的状态，这就带来了 **并发** 

操作系统是最早的并发程序

### 5.1 线程库：入门

线程之间共享内存

线程具有独立堆栈

`thread.h` ：基本线程库

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdatomic.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREAD 64
enum { T_FREE = 0, T_LIVE, T_DEAD, };
struct thread {
  int id, status;
  pthread_t thread;
  void (*entry)(int);
};

struct thread tpool[NTHREAD], *tptr = tpool;

void *wrapper(void *arg) {
  struct thread *thread = (struct thread *)arg;
  thread->entry(thread->id);
  return NULL;
}

void create(void *fn) {
  assert(tptr - tpool < NTHREAD);
  *tptr = (struct thread) {
    .id = tptr - tpool + 1,
    .status = T_LIVE,
    .entry = fn,
  };
  pthread_create(&(tptr->thread), NULL, wrapper, tptr);
  ++tptr;
}

void join() {
  for (int i = 0; i < NTHREAD; i++) {
    struct thread *t = &tpool[i];
    if (t->status == T_LIVE) {
      pthread_join(t->thread, NULL);
      t->status = T_DEAD;
    }
  }
}

__attribute__((destructor)) void cleanup() {
  join();
}
```

注意：`Ubuntu` 环境下对于 `pthread.h` 库的使用需要在编译时加上 `-lpthread` 选项

### 5.2 原子性：放弃

#### 状态机的隐含假设

> 世界上只有一个状态机

没有人能够干涉程序的状态，即对变量的 `load` 一定返回本线程最后一次 `store` 的值，这也是编译优化的基本假设，但是 **共享内存** 打破了这个假设

单独的一条汇编指令在不引入额外的硬件机制的情况下可能也不是原子的

### 5.3 顺序：放弃

保证执行顺序的方式

- 添加 `compile barrier` 

```c
asm volatile ("" ::: "memory")
```

- 使用 `volatile` 关键字标记变量 `load/store` 为不可优化

### 5.4 处理器间的可见性

现代处理器也是动态的 *编译器* ，电路将连续的指令 *编译* 为更小的微指令，并对指令的执行顺序和内容做出类似于编译器的 *编译优化* ，目的是在每一时钟周期里执行尽可能多的微指令：多路发射、乱序执行、按序提交，这也就是 CPU 的 `IPC Instructions Per Clock` 通常远大于 `1` 的原因

#### 宽松内存模型

> Relaxed/Weak Memory Model

目的是使单处理器的执行更高效

`x86` 处理器的每个 `thread` 向共享内存中进行写操作时会先写到一个独立的缓冲区中，各个缓冲区再按照其他硬件协议向共享内存中进行写操作并维护一致性

## 6. 并发控制基础

### 6.1 并发编程的困难

**编译优化 + 宽松内存模型** 导致并发执行的难以理解，`Verifying sequential consistency` 是 NP 完全问题

### 6.2 互斥和失败的尝试

### 6.3 Peterson 算法

### 6.4 自动化的意义

### 6.5 原子指令

## 7. 并发控制：互斥
