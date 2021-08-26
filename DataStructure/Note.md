> writer: VenusHui
> 
> time: 2021.08.01
> 
> Reference: Play With Data Structure 
## 《大话数据结构》阅读笔记

## 第一章 数据结构绪论

### 基本概念和术语
1. 数据：描述客观食物的符号，是在计算机中可以操作的对象， 是能被计算机识别，并输入给计算机处理的符号集合。

2. 数据元素：是组成数据的、有一定意义的基本单位，在计算机中通常作为整体处理/记录。

3. 数据项：一个数据元素可以由若干个数据项组成。数据项是不可分割的最小单位。

4. 数据对象：是性质相同数据元素的集合，是数据的子集。

5. 数据结构：是相互之间存在一种或多种特定关系的数据元素的集合。
   
### 逻辑结构和物理结构

1. 逻辑结构：数据对象中数据元素的相互关系

    - 集合结构：集合结构中的数据结构除了同属于一个集合之外，没有其他关系。
    - 线性结构：线性结构中的数据元素之间是一对一的关系。
    - 树形结构：树形结构中的数据元素之间存在一种一对多的层次关系。
    - 图形结构：图形结构中的数据元素是多对多的关系。

2. 物理结构/存储结构：数据的逻辑结构在激素啊集中的存储形式

   - 顺序存储结构：把数据元素存放在地址连续的存储单元内，其数据间的逻辑关系和物理关系是一致的。
   - 链式存储结构：把数据元素存放在任意的存储单元内，可以是连续/不连续的，存储关系不能反映逻辑关系，需要指针存放数据元素的地址。

### 数据类型

    一组性质相同的值的集合及定义在此集合上的一些操作的总称。
1. 分类：

   - 原子类型：不可以再分解的基本类型，包括整型、字符型等。
   - 结构类型：由若干个类型组合而成。

2. 抽象数据类型（ADT）

   一个数学模型及定义在该模型上的一组操作。

## 第二章 算法

### 算法

1. 定义：是解决特定问题求解步骤的描述，在计算机中表现为指令的有限序列，并且每条指令表示一个或多个操作。

2. 特性：

   - 输入输出：算法具有零个或多个输入，至少有一个或多个输出。
   - 有穷性：在执行有限的步骤之后，自动结束而不会出现无限循环，并且每一个步骤在可接受的时间内完成。
   - 确定性：算法的没哟个步骤具有确定的含义，不会出现二义性。
   - 可行性：算法的每一步都是可行的，可以通过执行有限次数完成。

3. 设计要求：

   - 正确性：具有输入、输出和加工处理无歧义性，能正确反映问题的需求，得到问题的正确答案。
   - 可读性：便于阅读，理解和交流。
   - 健壮性：输入数据不合法时也能进行相关处理，而不是产生异常或着莫名其妙的结果。
   - 时间效率高和存储量低

4. 算法效率的度量方法

   - 事后统计
   - 事前分析估算：将基本操作的数量表示成输入规模的函数
     - 算法采用的策略、方法
     - 编译产生的代码质量
     - 问题的输入规模
     - 机器执行指令的速度

5. 函数的渐进增长：给定两个函数$f(n)$,$g(n)$，如果存在一个整数N，使得对于所有的$n>N$总有$f(n)>g(n)$,则称$f(n)$的增长渐进快于$g(n)$。

6. 算法时间复杂度

   - 定义：进行算法分析时，语句总的执行次数$T(n)$是关于问题规模n的函数，算法的时间复杂度/时间量度记作$T(n)=O(f(n))$。表示随着问题规模n的增大，算法执行时间的增长率和$f(n)$的增长率相同。（大O记法）
   - 推到大O阶的方法
     - 用常数1取代运行时间中的所有加法常数。
     - 在修改后的运行次数函数中，只保留最高阶项。
     - 如果最高阶项存在且系数不唯一，则去除与其想乘的系数。

   - 常数阶：$O(1)$
   - 线性阶：$O(n)$
   - 对数阶：$O(logn)$
   - 平方阶：$O(n^2)$

7. 最坏情况与平均情况

8. 算法空间复杂度：必要时可以用空间来换取时间

## 第三章 线性表

      零个或多个数据元素的有限序列
1. 对于线性表$a_1,a_2...a_n$, 称$a_{i-1}$为$a_i$的**直接前驱元素**，$a_{i+1}$称为$a_i$的**直接后继元素**。元素个数`n`为线性表的长度，`n=0`时为空表，称`i`为数据元素$a_i$的位序。

   - 在较为复杂的线性表中，一个数据元素可以由若干个[数据项](#基本概念和术语)组成

2. 线性表的抽象数据类型

```
ADT LinerList // ADT short for abstract data type
Data:
   DataType a1;
   DateType a2;
   ...
   DataType an;

Operation:
   InitList(*L);           // 创建一个空表
   ListEmpty(L);           // 判断线性表是否为空
   ClearList(*L);          // 清空线性表
   GetElem(L, i, *e);      // 将L中位置i的元素值返回给e
   LocateElem(L, e);       // 在L中查找与e相等的元素
   ListInsert(*L, i, e);   // 在L的第i个位置插入元素e
   ListDelete(*L, i);      // 删除L中第i个位置的元素
   ListLength(L);          // 返回线性表L的长度
end ADT
```

### 线性表的顺序存储结构

   - 顺序存储定义：用一段地址连续的存储单元依次存储线性表的数据元素。
   - 顺序存储方式：可以借助一维数组

```cpp
#define MAXSIZE 20
typedef int ElemType;
typedef struct{
   ElemType data[MAXSIZE];
   int length;
}SqList;
```
   - 数组长度与线性表长度不一定相等

   - 地址计算方法：$loc(a_i) = loc(a_1) + (i - 1) \times c$, 其中$loc(a_1)$为数组的首地址，$c$为每个数据元素所占据的空间。
   - 存取时间性能：$O(1)$， 这种结构称为**随机存取结构**。

### 顺序结构的插入和删除

   - 获得元素操作，时间复杂度$O(1)$

```cpp
ElemType GetElem(SqList L, int i)
{
   if (i >= 0 && i < L.length){
      return L.data[i - 1];
   }
   else{
      return false;
   }
}
```
   - 插入操作，时间复杂度$O(n)$

```cpp
bool ListInsert(SqList* L, int i, ElemType e)
{
   if (L->length == MAXSIZE){ // 当前线性表已满
      return false;
   }
   for (int j = L->length - 1, j >= i - 1, j--){
      L->data[j + 1] = L->data[j]; // 插入操作倒序处理可以省去引入变量temp
   }
   L->data[i - 1] = e;
   L->length++;
   return true;
}
```
   - 删除操作，时间复杂度$O(n)$

```cpp
ElemType ListDelete(SqList* L, i)
{
   if (L->length = 0){
      return false;
   }
   ElemType e = L->data[i - 1];
   for (int j = i - 1, j < L->length - 1, j++){
      L->data[j] = L->data[j + 1]; // 删除操作正序处理可以省去引入变量temp
   }
   L->length--;
   return e;
}
```
   - 顺序存储结构的优劣
     - 读取快速，但插入和删除需要移动大量的元素。
     - 难以预估需要的存储空间容量，容易造成存储空间的碎片化浪费。

### 线性表的链式存储结构

   - 链式存储定义：用任意的一组存储单元存储线性表的数据元素，这组存储单元可以是连续的，也可以是不连续的。
   - 链式存储方式：对于数据元素$a_i$，需要（在指针域中）存储数据元素的信息以及（在指针域中）存储其后继元素的存储地址，这两部分信息组成数据元素$a_i$的存储映像，称为**结点**。
   - 由于此链表每个结点只包含一个指针域，所以叫做**单链表**。
   - 头指针与头结点
     - 链表中第一个结点的存储位置为头指针。
     - 通常会在单链表的第一个结点前附设一个结点，指针域为头指针，数据域存储线性表长度等公共数据。
     - 无论链表是否为空，头指针都不为空。
     - 头结点的意义：使`在第一元素结点前插入结点`和`删除第一结点`两项操作与其他结点相同。

   - 链式存储结构的代码描述

```cpp
typedef struct Node{
   ElemType data;
   struct Node* next;
}Node;
typedef struct Node* LinkList;
```

### 单链表的读取、插入和删除操作

   - 读取操作，时间复杂度$O(n)$

```cpp
ElemType GetElem(LinkList L, int i)
{
   int j = 1;
   LinkList p;
   p = L->next;
   while (p && j < i){
      p = p->next;
      j++;
   }
   if (!p || j > i){
      return false;
   }
   return p->data;
   // LinkList p = L->next;
   // for (int j = 1, j < i && p != nullptr, j++){
   //    p = p->next;
   // }
   // if (p == nullptr){
   //    return false;
   // }
   // else{
   //    return p->data;
   // }
}
```

   - 插入操作，时间复杂度$O(n)$

```cpp
bool ListInsert(LinkList* L, int i, ElemType e)
{
   int j = 1;
   LinkList p = *L;
   while (p && j < i){
      p = p->next;
      j++;
   }
   if (p == nullptr || j > i){
      return false;
   }
   LinkList s = new Node;
   s->data = e;
   s->next = p->next;
   p->next = s;
   delete s;
}
```

   - 删除操作，时间复杂度$O(n)$

```cpp
ElemType ListDelete(LinkList *L, int i)
{
   int j = 1;
   LinkList p = *L;
   while (p && j < i){
      p = p->next;
      j++;
   }
   if (p->next == nullptr || j > i){
      return false;
   }
   LinkList temp = p->next;
   p->next = temp->next;
   ElemType ans = temp->data;
   delete temp;
   return ans;
}
```

### 单链表的整表创建

   - 头插法

```cpp
void CreateListtHead(LinkList *L, int n)
{
   LinkList p;
   srand(time(0)); // 初始化随机数种子
   *L = new Node; // 头结点
   (*L)->next = nullptr;
   for (int i = 0; i < n; i++)
   {
      p = new Node;
      p->data = rand() % 100 + 1;
      p->next = (*L)->next;
      (*L)->next = p; // 这里是插入到表头，故名头插法。
   }
}
```

   - 尾插法

```cpp
void CreateListTail(LinkList *L, int n)
{
   LinkList p, r;
   srand(time(0));
   *L = new Node;
   r = *L;
   for (int i = 0; i < n; i++)
   {
      p = new Node;
      p->data = rand() % 100 + 1;
      r->next = p;
      r = p->next; // 重新使r指向尾部
   }
   r->next = nullptr; // 链表结束
}
```

### 单链表的整表删除

```cpp
void ClearList(LinkList *L)
{
   LinkList p, q;
   p = (*L)->next; // L为头结点，p指向第一个节点
   while (p != nullptr)
   {
      q = p->next;
      delete p;
      p = q;
   }
   (*L)->next = nullptr;
}
```

### 单链表结构与顺序存储结构的优缺点

   - 当需要频繁查找、很少进行插入和删除操作时，宜使用顺序存储结构，反之宜使用单链表结构。
   - 当不清楚线性表的数据规模或数据规模变化较大时，宜采用单链表结构。

### 静态链表

- 定义：用数组描述的链表称作静态链表。
- 存储方式：游标实现法，即数组的每个元素都由数据域和游标，游标相当于单链表中的`next指针`，用于存放直接后继元素的下标。
- 应用：在不支持指针的语言中用游标的方式描述链表，目前应用很少。

```cpp
typedef struct Component{
   ElemType data;
   int cur; // 游标
}Component, StaticLinkList[MAXSIZE]; // 通常会为问题预留足够的空间，。
```
- 特殊处理：
  - 数组第一个元素的`cur`存放备用链表（未被使用的数组元素称为备用链表）的第一个结点的下标。
  - 数组的最后一个元素的`cur`存放第一个有树枝的元素的下标，相当于单链表的头结点。

- 静态链表的初始化、插入、删除等操作
  - 初始化

```cpp
void InitList(StaticLinkList space)
{
   for (int i = 0; i < MAXSIZE - 1; i++){
      space[i].cur = i + i; // 这里是在初始化游标
   }
   space[MAXSIZE - 1].cur = 0;
}
```
  - 为了模拟动态链表中的结点申请与释放，我们可以自己写`Malloc_SSL`和``Free_SSL`函数

```cpp
// 若备用空间链表为空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space)
{
   int i = space[0].cur;
   if (space[0].cur != 0){
      space[0].cur = space[i].cur; // 将第一个结点的cur改为指向备用链表中的下一个结点
   }
   return i;
}

// 将下表为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
   space[k].cur = space[0].cur;
   space[0].cur = k;
}
```
  - 插入操作

```cpp
bool ListInsert(StaticLinkList L, int i, ElemType e)
{
   if (i < 1 || i > ListLength(L) + 1){
      return false;
   }
   int k = MAXSIZE - 1;
   int j = Malloc_SSL(L); // 获得备用链表中空闲分量的下标
   if (j != 0){
      L[j].data = e;
      for (int l = 1; l < i; l++){ // 从表头开始遍历
         k = L[k].cur;
      }
      L[j].cur = L[k].cur;
      L[k].cur = j;
      return true;
   }
   return false;
}
```
  - 删除操作

```cpp
bool ListDelete(StaticLinkList L, int i)
{
   if (i < 1 || i > ListLength(L)){
      return false;
   }
   int k = MAXSIZE - 1, j;
   for (j = 1; j < i; j++){
      k = L[k].cur;
   }
   j = L[k].cur;
   L[k].cur = L[j].cur;
   Free_SSL(L, j);
   return true;
}
```
- 静态链表的优劣分析
  - 在插入、删除操作时只需要修改游标，不需要移动元素，改进了顺序存储结构中插入和删除操作需要大量移动元素的缺陷。
  - 没有解决连续存储分配带来的表长难以确定的问题，且在存储上失去了链式存储结构随机存取的特性（无法利用碎片化空间）。

### 循环链表

- 将单链表终端结点的指针端由空指针改为头结点，使单链表成环为循环链表。
- 尾指针：与单链表的头指针不同，循环链表通常使用指向终端结点的尾指针`rear`表示，这样可以在$O(1)$的时间复杂度下查找到终端结点，并且简化将两个循环链表合二为一的步骤。

### 双向链表

- 在单链表的指针域中追加一个指向其直接前驱元素的指针`piror`，使单链表成为双向链表。
- 双向链表也可以是循环链表。

## 第四章 栈与队列

### 栈的定义
    栈是限定仅在表尾进行插入和删除操作的线性表。
- 允许进行插入和删除的一端称为栈顶，另一端称为栈底。

### 栈的抽象数据类型

```
ADT Stack
Data: // 与线性表相同
   DataType a1;
   DateType a2;
   ...
   DataType an;
Operation:
   InitStack(*S);       // 初始化，建立一个空栈
   DestroyStack(*S);    // 若栈S存在，则销毁它
   ClearStack(*S);      // 清空栈S
   StackEmpty(*S);      // 判断栈是否为空
   GetTop(*S);          // 若栈存在且非空获取栈顶元素
   Push(*S, e);         // 进栈操作
   Pop(*S);             // 出栈操作
   StackLength(S);      // 返回栈S的元素个数
end ADT
```

### 栈的顺序存储结构(顺序栈)

- 栈的顺序存储结构与线性表相似，也是利用数组来实现，由于首元素都存在栈底，我们通常使用下标为0的一端作为栈底。

```cpp
typedef int ElemType;
typedef struct{
   ElemType data[MAXSIZE];
   int top; // 用于栈顶指针(栈顶元素的数组下标，存在一个元素时top = 0)，通常把空栈的判定条件定为top = -1;
}SqStack;
```
- 进栈操作，时间复杂度$O(1)$

```cpp
bool Push(SqStack* S, ElemType e)
{
   if (S->top == MAXSIZE - 1){
      return false; // 此栈已满
   }
   S->data[++S->top] = e; // 先栈顶指针加一，后元素进栈
   return S->data[S->top];
}
```
- 出栈操作，时间复杂度$O(1)$

```cpp
ElemType Pop(SqStack* S)
{
   if (S->top = -1){
      return false; // 此栈为空栈
   }
   return S->data[top--]; // 先元素出栈，后栈顶指针回退
}
```

### 两栈共享空间

- 通常情况下可以用一个数组来存储两个类型相同的栈，以解决一个栈已满而另一个栈还有很多剩余空间的问题。

```cpp
// 可以理解为两个栈在数组的两端向中间靠拢
typedef struct{
   ElemType data[MAXSIZE * 2];
   int top1; // 栈1的栈顶指针
   int top2; // 栈2的栈顶指针
   /* 栈1为空的判定条件：top = -1;
      栈2为空的判定条件：top = MAXSIZE * 2 - 1;
      栈满的判定条件：top1 + 1 = top2; */
}
```
- 两栈共享空间的模式在两个栈具有相反的空间需求时十分好用，即一个栈增长，另一个栈随之缩短的模式

### 栈的链式存储结构(链栈)

- 由于单链表有头指针，通常考虑将栈顶放在单链表的头部，使头指针成为栈顶指针，插入元素类比[头插法](#单链表的整表创建)。
- 由于栈顶在头部，所以链栈不需要头结点。

```cpp
typedef struct StackNode{
   ElemType data;
   struct StackNode* next; // 我的理解是：这里typedef还未生效，使用StackNode必须在前面加struct
}StackNode, *LinkStackPtr; // 相当于typedef StackNode* LinkStackPtr

typedef struct LinkStack{
   LinkStackPtr top;       // 栈顶指针
   int count;              // 元素数量
}LinkStack;
```

- 进栈操作，时间复杂度$O(1)$

```cpp
bool Push(LinkStack* S, ElemType e)
{
   // 链栈不存在栈满的情况（存在会出大问题的）
   LinkStackPtr p = new StackNode;
   p->data = e;
   p->next = S->top;
   S->top = p;
   S->count++;
   return true;
}
```
- 出栈操作，时间复杂度$O(1)$

```cpp
ElemType Pop(LinkStack* S)
{
   LinkStackPtr p;
   if (StackEmpty(*S)){
      return false;
   }
   ElemType ans = S->top->data;
   p = S->top;
   S->top = S->top->next;
   S->count--;
   return ans;
}
```

### 栈的应用
- 递归
  - 定义：直接调用自己或者通过一系列的调用语句间接地调用自己的函数称作递归函数。
  - 每个递归定义必须至少有一个条件，满足时递归不再进行，即不再引用自身而是返回值退出。

- 四则运算表达式求值
  - 后缀表示法（逆波兰表示法）：不需要括号，且所有符号都在运算数字的后面出现的表示方法。如`9 3 1 - 3 * + 10 2 / +`，其对应的中缀表达式为`9 + (3 - 1) * 3 + 10 / 2`。
  - 中缀表达式转后缀表达式：从左到右遍历中缀表达式的每个数字和符号，若是数字则直接输出，若是符号，则判断与栈顶符号的优先级，是右括号或优先级不高于栈顶符号，则栈中元素依次出栈输出，并将当前符号进栈，一直到最后输出后缀表达式为止。
  - 后缀表达式的计算结果：从左到右遍历后缀表达式的每个数字及符号，遇到是数字就进栈，遇到是符号就将处于栈顶的两个数出栈进行运算，运算结果进栈，一直到获得最终结果。

### 队列(queue)的定义
    队列是只允许在一端进行插入操作，而在另一端进行删除操作的线性表。
- 允许插入的一端叫队尾，允许删除的一端叫队头。

### 队列的抽象数据类型

```
ADT Queue
Data: // 与线性表相同
   DataType a1;
   DateType a2;
   ...
   DataType an;
Operation:
   InitQueue(*Q);       // 初始化操作，建立一个空队列
   DestroyQueue(*Q);    // 销毁队列
   ClearQueue(*Q);      // 将队列Q清空
   QueueEmpty(Q);       // 判断队列Q是否为空
   GetHead(Q);          // 返回队列Q的对头元素
   EnQueue(*Q, e);      // 入队操作
   DeQueue(*Q);         // 出队操作
   QueueLength(Q);      // 获取队列长度
end ADT
```
### 循环队列

- 队列的顺序存储结构的不足：利用数组实现的顺序存储结构若是将下标为零的点设置为队头，则进行出队操作时的时间复杂度为$O(n)$，若采用游标的方式设置队头及队尾，在多次进行出队入队操作后，队尾游标可能会位移到数组之外造成`队列的假溢出`，所以要将此时队头位置空出来的空间与队尾相连进行再利用，也就是循环队列的由来。

- 循环队列的定义：队列的这种头尾相接的顺序存储结构称为循环队列。

- 循环队列的存储方式：引入两个指针`front`，`rear`分别指向队头和队尾，当`rear`应指向`MAXSIZE`的位置时将其改为指向下标为0的位置。
  - 判断队列满的条件：由于此时在`front == rear`的条件下，队列可能为满也可能为空，所以我们修改队列满的条件，通常情况下我们认为**数组中只剩余一个空闲单元**的时候队列为满。此时队列满的条件为：`(rear + 1) / MAXSIZE == front`（由于`rear`和`front`的大小关系不明，所以用取模整合）。
  - 同时应用取模整合`front`和`rear`大小为一个问题的还有计算队列长度的公式：`(rear - front + MAXSIZE) % MAXSIZE`。

- 循环队列的代码实现

```cpp
typedef int ElemType;
typedef struct{
   ElemType data[MAXSIZE];
   int front;  // 头指针
   int rear;   // 尾指针
}SqQueue;

// 初始化
bool InitQueue(SqQueue* Q)
{
   Q->front = 0;
   Q->rear = 0;
   return true;
}

// 获取队列长度
int QueueLength(SqQueue Q)
{
   return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 入队操作
bool EnQueue(SqQueue* Q, ElemType e)
{
   if ((Q->rear + 1) % MAXSIZE == Q->front){ // 判断队列是否为满
      return false;
   }
   Q->data[Q->rear] = e;
   Q->rear = (Q->rear + 1) % MAXSIZE; // 尾指针后移，若超出则转移到数组头部
   return true;
}

// 出队操作
ElemType DeQueue(SqQueue* Q)
{
   if (Q->front == Q->rear){ // 判断队列是否为空
      return false;
   }
   ElemType ans = Q->data[Q->front];
   Q->front = (Q->front + 1) % MAXSIZE;
   return ans;
}
```
- 循环队列相关操作的时间复杂度都不高，但会受到数组空间的制约。

### 队列的链式存储结构(链队列)

```cpp
typedef int ElemType;
typedef struct QNode{
   ElemType data;
   struct QNode* next;
}QNode, *QueuePtr;
typedef struct{
   QueuePtr front, rear;
}LinkQueue;

// 入队操作
bool EnQueue(LinkQueue* Q, ElemType e)
{
   QueuePtr p = new QNode; // 虽然是在函数体中，但new的内存一般在遇到相应的delete才会释放，函数结束不会释放这一部分内存
   if (p != nullptr){
      p->data = e;
      p->next = nullptr;
      Q->rear->next = p;
      Q->rear = p;
      return true;
   }
   return false;
}

// 出队操作
ElemType DeQueue(LinkQueue* Q)
{
   QueuePtr p;
   if (Q->front == Q->rear){
      return false;
   }
   p = Q->front->next;
   ElemType ans = p->data;
   Q->front->next = p->next;
   if (Q->rear == p){
      Q->rear = Q->front;
   }
   return ans; // 这里会自动释放p
}
```

- 与循环队列的对比：虽然两者基本操作的时间复杂度均为$O(1)$，但由于链队列在申请和释放结点上的时间开销，在频繁进行出队和入队操作操作时，时间性能上不如循环队列，所以在能预见队列长度最大值时，优先使用循环队列。

## 串(string)

### 串的定义
    由零个或多个字符组成的有限序列，又叫字符串

- 一般记为$s = "a_1a_2···a_n" (n >= 0)$。串中的字符数目n称为串的长度，零个字符的字符串称为空串。
- 串的相邻字符之间具有前驱和后继的关系。
- 子串与主串：串中任意连续个数的连续字符组成的子序列成为该串的子串，包含子串的串成为主串，子串在主串中的位置为子串的第一个字符在主串中的序号。
- 串的比较：给定两个串$s = “a_1a_2···a_n”, t = “b_1b_2···b_m”$，当满足以下条件之一时，$s < t$：
  - $n < m, 且a_i = b_i(i = 1, 2, ···, n)$。
  - $存在某个k \leqslant min(m, n)，使得a_i = b_i(i = 1, 2, ···, k - 1), a_k < b_k$。