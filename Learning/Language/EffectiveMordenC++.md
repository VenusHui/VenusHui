# Effective Morden C++

> followed by Bilibili Up: https://space.bilibili.com/218427631

[TOC]

## Base 1：顶层 Const 与底层 Const

```cpp
const int *const p = new int(10);
底层			  顶层

```

- 顶层 const：表示所修饰的部分本身是一个常量
- 底层 const：表示所修饰的部分所指的对象是一个常量

**当执行对象拷贝操作时，常量的顶层 const 不受影响，而底层 const 必须一致** 

```cpp
const int *p1 = p;	// 编译通过
int *p2 = p;				// Error
int *const p3 = p;	// Error
```

- 引用不是对象，且不进行拷贝

  - 引用本身总是顶层 const，因为引用一旦被初始化就不能绑定到其他对象，所以引用声明中的 const 均为底层 const

- 常量引用如果在左侧，右侧可以接任何东西

  ```cpp
  const int a = 10;
  int &p = a; 				// Error，非常量引用 = 常量
  const int &p1 = a; 	// 编译通过，常量引用
  int p2 = p1; 				// 编译通过，非常量 = 常量引用
  ```

## Base 2：值类型与右值引用

> 编译选项：
>
> ```cmake
> MAKE_CXX_STANDARD 14
> MAKE_CXX_FLAGS --fno-elide-constructors # 禁止返回值优化
> ```

### 函数调用的拷贝次数

对于下面这个函数调用：

```cpp
int geta() {
		int a = 10;
		return a;
}
int x = geta();
```

在关闭返回值优化是，该调用首先会在函数返回时将局部变量 a 赋值给临时对象，再将临时对象赋值给 x，共执行两次拷贝

### 表达式类型

C++98 的表达式类型（值类型）

- 左值：指向特定类型的具名对象，可以取地址
- 右值：临时对象，字符串除外的字面量，不可以取地址

  - 字符串字面量可以取地址，为左值

    ```cpp
    &"hello world";
    char str[12] = "hello world";
    const char *str = "hello world";
    ```


C++11 的表达式类型

- 泛左值（glvalue）
  - 左值（lvalue）
  - 将亡值（xvalue）
- 右值（rvalue）
  - 将亡值（xvalue）
  - 纯右值（prvalue）

### 赋值操作的解法

- 拷贝
- 引用
- 移动

### 右值引用与移动语义

右值引用：

```cpp
const int x = 10;
int &x1 = x;		// 左值引用，不接受右值，Error
int &&x2 = x;		// 右值引用，只接受右值，编译通过
```

移动语义：

```cpp
std::move() // 将左值转化为右值（转化后原来的左值的生命周期结束）
```

- 转化得到的值为 **将亡值** 

如何得到将亡值：

- `static_cast<int &&>()` 
- `std::move()` 
- 临时变量实质化（C++17 引入）

纯右值也可以 `std::move()` 

```cpp
std::move(10);
```

类中没有实现移动构造，`std::move()` 时仍为拷贝，即：移动语义实际上没有移动，只是做了类似类型转换的工作

```cpp
class A {
private:
    char* pool_;
public:
    static const int size = 1024;

    // 构造函数
    A() : pool_(new char[size]) {}

    // 拷贝构造函数
    A(const A &other) : pool_(new char[size]) {
        std::cout << "copy" << std::endl;
        memcpy(pool_, other.pool_, size);
    }

    // 移动构造函数，若不实现，则 A b = a; 时仍调用拷贝构造函数
    A(A &&other) {
        std::cout << "move" << std::endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }

    // 析构函数
    ~A() {
        if (pool_ != nullptr) {
            delete[] pool_;
        }
    }
};
```

右值引用仍为左值

```cpp
int x = 10;
int &&y = std::move(x); // y 为左值
```

右值绑定到右值引用上不会发生移动构造也不会发生拷贝构造：

```cpp
A a;
A &&b = std::move(a); // 与 A &c = a; 等价
```

## Base 3：数组指针与函数指针

### 数组指针

数组相关的数据类型

> 数组是一个不完全的容器，C++ 不建议使用 `[]` 

```cpp
int array[5] = { 0, 1, 2, 3, 4 };
```

- array 的数据类型为 `int[5]` 

  ```cpp
  int *ptr = array; // 数组指针
  ```

- array 作为数组名 **退化** 为指针

  ```cpp
  int (*ptr)[5] = &array; // 指针数组
  ```

数组名作为参数传递时会发生退化

```cpp
// 下面三种写法对于编译器来说是等价的，都等于 void func(int *a);
void func(int a[5]);
void func(int a[100]);
void func(int a[]);
void func(int *a);

// 下面两种写法不等价
void func(int (*ptr)[5]);
void func(int (*ptr)[100]);
```

### 函数指针

函数相关的数据类型

- func 的数据类型为  `bool(int, int)` 

  ```cpp
  bool func(int a, int b);
  ```

- funcptr 的数据类型为 `bool(*)(int, int)` ，函数指针

  ```cpp
  bool (*funcptr)(int a, int b);
  ```

  - 函数指针赋值

    ```cpp
    funcptr = &func;
    funcptr = func; // 函数名退化为一个函数指针
    ```

  - 函数指针使用

    ```cpp
    bool f = (*funcptr)(1, 2);
    bool f = funcptr(1, 2); // 函数指针 “升级” 为一个函数
    ```

  - 函数指针作为形参

    ```cpp
    using func = bool(int, int);
    using funcptr = bool (*)(int, int);
    
    // 下面两种形式等价
    void f(int a, funcptr foo);
    void f(int a, funcptr *foo);
    ```

  - 函数指针作为返回值

    ```cpp
    // 下面两种形式等价
    funcptr f(int a, int b);
    func* f(int a, int b);
    
    // 不使用类型别名的写法
    bool (*f(int a, int b))(int, int);
    ```

  - 函数的引用

    ```cpp
    bool (&funref)(int, int) = func;
    ```

### 类型别名

两种方式：`typedef` 和 `using` 

```cpp
typedef bool (*funcptr)(int, int);
using funcptr = bool (*)(int, int);

typedef bool func(int, int);
using func = bool(int, int);

// func* = funcptr
```

## Item 1：理解模板类型推导

模板类型的位置不影响 `const` 的推导结果

- 当 T 被推导为 `int *` 时，这里的 `const` 都是顶层 `const` 

```cpp
template <typename T>

// 下面两种写法等价
void (const T param);
void (T const param);
```

顶层 const 不构成重载

```cpp
// 下面这两个函数不构成重载，编译会报错
void func(int a);
void func(const int a);
```

函数指针的底层 const 似乎只能用类型别名表示出来

```cpp
int func(int a) { return 10; }
int (*funcptr)(int) = func;

int (const *funcptr)(int) = func; // 顶层 const

using F = int(int);
F *const f1 = func; // 顶层 const
const F *f2 = func; // 底层 const，借助类型别名
```

函数引用的底层 const 会被编译器忽略

```cpp
int (&funcref)(int) = func;
const &F funcref = func; // 这里 funcref 的类型为 F&，而非 const F&
```

```cpp
template <TypeName T>
void func(ParamType param); // ParamType 可以为 T, T*, T&, const T, const T*, const T&, T *const, const T *const, T &&, const T &&
```

通用引用

```cpp
void func(T && param); // 通用引用只能这样写，T 前不能加 const
```

- 传入左值，`ParamType` 为左值引用
- 传入右值，`ParamType` 为右值引用

```cpp
#include <iostream>

template <typename T>
void f(T param) {
    std::cout << param << std::endl;
}

template <typename T>
void fptr(T* param) {
    std::cout << param << std::endl;
}

template <typename T>
void fref(T& param) {
    std::cout << param << std::endl;
}

template <typename T>
void cf(const T param) {
    std::cout << param << std::endl;
}

template <typename T>
void cfptr(const T* param) {
    std::cout << param << std::endl;
}

template <typename T>
void fcptr(T* const param) {
    std::cout << param << std::endl;
}

template <typename T>
void cfcptr(const T* const param) {
    std::cout << param << std::endl;
}

template <typename T>
void cfref(const T& param) {
    std::cout << param << std::endl;
}


template <typename T>
void frref(T&& param) {
    std::cout << param << std::endl;
}

template <typename T>
void cfrref(const T &&param) {
    std::cout << param << std::endl;
}


bool func(int a, int b) {
    return true;
}

int main() {

    // 左值
    int a = 10;
    f(a); // T: int, ParamType: int
    // fptr(a);
    fref(a); // T: int, ParamType: int &
    cf(a); // T: int, ParamType: int | 顶层 const 不构成重载
    // cfptr(a);
    // fcptr(a);
    // cfcptr(a);
    cfref(a); // T: int, ParamType: const int & | const T& 这里的 const 为底层 const
    frref(a); // T: int &, ParamType: int & | 通用引用传入左值，ParamType 为左值引用，T 被推导为 int &，与 && 发生了引用折叠
    // cfrref(a); // 只能传入右值


    // 指针
    int *aptr = &a;
    f(aptr); // T: int *, ParamType: int *
    fptr(aptr); // T: int , ParamType: int *
    fref(aptr); // T: int *, ParamType: int *&
    cf(aptr); // T: int *, ParamType: int * | 顶层 const 不构成重载
    cfptr(aptr); // T: int, ParamType: const int * | const T* 这里的 const 为底层 const
    fcptr(aptr); // T: int, ParamType: int * | T *const 这里的 const 为顶层 const
    cfcptr(aptr); // T: int, ParamType: const int * | 顶层 const 忽略
    cfref(aptr); // T: int *, ParamType: int * const & | 底层 const，表示一个指向位置不变的指针的引用
    frref(aptr); // T: int * &, ParamType: int * &
    // cfrref(aptr);


    // 引用
    int &aref = a;
    f(aref); // T: int, ParamType: int | 通过值传递参数时，引用性会被忽略
    // fptr(aref);
    fref(aref); // T: int, ParamType: int &
    cf(aref); // T: int, ParamType: int
    // cfptr(aref);
    // fcptr(aref);
    // cfcptr(aref);
    cfref(aref); 
    frref(aref); // T: int &, ParamType int &
    // cfrref(aref);


    // 顶层 const 指针
    int *const acptr = &a;
    f(acptr); // T: int *, ParamType: int *
    fptr(acptr); // T: int, ParamType: int *
    fref(acptr); // T: int *const, ParamType: int *const &
    cf(acptr); // T: int *, ParamType: int * | 顶层 const 忽略
    cfptr(acptr); // T: int, ParamType: const int * | 这里的 const 为底层 const，不能忽略
    fcptr(acptr); // T: int, ParamType: int * | 顶层 const 忽略
    cfcptr(acptr); // T: int, ParamType: const int *
    cfref(acptr); // T: int *, ParamType: const (int *) & -> int * const & | 这里的 const 修饰 int *，而不是 &
    frref(acptr); // T: int * const &, ParamType: int * const &
    // cfrref(acptr);
    

    // 常量
    const int ca = 10;
    f(ca); // T: int, ParamType: int
    // fptr(ca);
    fref(ca); // T: const int, ParamType: const int &
    cf(ca); // T: int, ParamType: int
    // cfptr(ca);
    // fcptr(ca);
    // cfcptr(ca);
    cfref(ca); // T: int, ParamType: const int &
    frref(ca); // T: const int &, ParamType: const int &
    // cfrref(ca);


    // 底层 const 指针
    const int *captr = &ca;
    f(captr); // T: const int *, ParamType: const int *
    fptr(captr); // T: const int, ParamType: const int *
    fref(captr); // T: const int *, ParamType: const int * &
    cf(captr); // T: const int *, ParamType: const int * | 顶层 const 省略
    cfptr(captr); // T: int, ParamType: const int *
    fcptr(captr); // T: const int, ParamType: const int *
    cfcptr(captr); // T: int, ParamType: const int *
    cfref(captr); // T: const int *, ParamType: const int * const &
    frref(captr); // T: const int * &, ParamType: const int * &
    // cfrref(captr);


    // 常量引用
    const int &caref = ca;
    f(caref); // T: int, ParamType: int | 通过值传递参数时，引用性会被忽略
    // fptr(caref);
    fref(caref); // T: const int, ParamType: const int &
    cf(caref); // T: int, ParamType: int
    // cfptr(caref);
    // fcptr(caref);
    // cfcptr(caref);
    cfref(caref); // T: int, ParamType: const int &
    frref(caref); // T: const int &, ParamType: const int &
    // cfrref(caref);
    

    // 常量的常量指针
    const int * const cacptr = &ca;
    f(cacptr); // T: const int *, ParamType: const int *
    fptr(cacptr); // T: const int, ParamType: const int *
    fref(cacptr); // T: const int * const, ParamType: const int * const &
    cf(cacptr); // T: const int *, ParamType: const int *
    cfptr(cacptr); // T: int, ParamType: const int * | 顶层 const 忽略，const T * 这里的 const 被推导为底层 const
    fcptr(cacptr); // T: const int, ParamType: const int * | T * const 这里的 const 被推导为顶层 const，所以 T 被推导为 const int，ParamType 中的 顶层 const 忽略
    cfcptr(cacptr); // T: int, ParamType: const int *
    cfref(cacptr); // T: const int *, ParamType: const int * const &
    frref(cacptr); // T: const int * const &, ParamType: const int * const &
    // cfrref(cacptr);

    // 右值引用
    int &&ra = std::move(a);
    f(ra); // T: int, ParamType: int | 模版参数推导时，右值引用会被推导为右值
    // fptr(ra);
    fref(ra); // T: int, ParamType: int &
    cf(ra); // T: int, ParamType: int
    // cfptr(caref);
    // fcptr(caref);
    // cfcptr(caref);
    cfref(ra); // T: int, ParamType: const int &
    frref(ra); // T: int &, ParamType: int &
    // cfrref(ra);

    // 右值引用常量
    const int &&rca = std::move(a);
    f(rca); // T: int, ParamType: int
    // fptr(rca);
    fref(rca); // T: const int, ParamType: const int &
    cf(rca); // T: int, ParamType: int
    // cfptr(caref);
    // fcptr(caref);
    // cfcptr(caref);
    cfref(rca); // T: int, ParamType: const int &
    frref(rca); // T: const int &, ParamType: const int &
    // cfrref(rca);

    // 右值
    10;
    f(10); // T: int, ParamType: int
    // fptr(10);
    // fref(10);
    cf(10); // T: int, ParamType: int
    // cfptr(caref);
    // fcptr(caref);
    // cfcptr(caref);
    cfref(10); // T: int, ParamType: const int &
    frref(10); // T: int, ParamType: int &&
    cfrref(10); // T: int, ParamType: const int &&

    // 数组
    int array[2] = { 0, 1 };
    f(array); // T: int *, ParamType: int * | 数组名退化为指针
    fptr(array); // T: int, ParamType: int *
    fref(array); // T: int [2], ParamType: int & [2] | 数组名作为引用参数传递时，类型信息会保留
    cf(array); // T: int *, ParamType: int * | 顶层 const 省略
    cfptr(array); // T: int, ParamType: const int *
    fcptr(array); // T: int, ParamType: int *
    cfcptr(array); // T: int, ParamType: const int *
    cfref(array); // T: int [2], ParamType: const int & [2]
    frref(array); // T: int & [2], ParamType: int & [2]
    // cfrref(array);

    // 数组指针
    int (*arrayptr)[2] = &array;
    f(arrayptr); // T: int * [2], ParamType: int * [2]
    fptr(arrayptr); // T: int [2], ParamType: int * [2]
    fref(arrayptr); // T: int * [2], ParamType: int *& [2]
    cf(arrayptr); // T: int * [2], ParamType: int * [2]
    cfptr(arrayptr); // T: int [2], ParamType: const int * [2]
    fcptr(arrayptr); // T: int [2], ParamType: int * [2]
    cfcptr(arrayptr); // T: int [2], ParamType: const int * [2]
    cfref(arrayptr); // T: int * [2], ParamType: int (* const &) [2]
    frref(arrayptr); // T: int * & [2], ParamType: int * & [2]
    // cfrref(arrayptr);

    // 数组引用
    int (&arrayref)[2] = array;
    f(arrayref); // T: int *, ParamType: int *
    fptr(arrayref); // T: int, ParamType: int * | 通过值传递参数时，引用性会被忽略
    fref(arrayref); // T: int [2], ParamType: int & [2] | 类型信息保留
    cf(arrayref); // T: int *, ParamType: int *
    cfptr(arrayref); // T: int, ParamType: const int *
    fcptr(arrayref); // T: int, ParamType: int *
    cfcptr(arrayref); // T: int, ParamType: int *
    cfref(arrayref); // T: int [2], ParamType: const int & [2]
    frref(arrayref); // T: int & [2], ParamType: int & [2]
    // cfrref(arrayref);

    // 字符串字面量（数组）
    "hello world"; // 类型为 const char[12]
    f("hello world"); // T: const char *, ParamType: const char * | 退化为指针
    fptr("hello world"); // T: const char, ParamType: const char *
    fref("hello world"); // T: const char[12], ParamType: const char & [12]
    cf("hello world"); // T: const char *, ParamType: const char * | 模板里的时顶层 const 省略，而 T 中的为底层 const 不可省略
    cfptr("hello world"); // T: char, ParamType: const char *
    fcptr("hello world"); // T: const char, ParamType: const char *
    cfcptr("hello world"); // T: char, ParamType: const char *
    cfref("hello world"); // T: char [12], ParamType: const char & [12]
    frref("hello world"); // T: const char & [12], ParamType: const char & [12]
    // cfrref("hello world");

    // 函数
    func;
    f(func); // T: bool(*)(int, int), ParamType: bool(*)(int, int) | 函数名退化为指针
    fptr(func); // T: bool(int, int), ParamType: bool(*)(int, int)
    fref(func); // T: bool(int, int), ParamType: bool(&)(int, int) | 函数名作为参数传递时类型信息保留
    cf(func); // T: bool(*)(int, int), ParamType: bool(*)(int, int) | 顶层 const 忽略
    // cfptr(func); | 函数的底层 const 似乎只能用类型别名表示出来
    fcptr(func); // T: bool(*)(int, int), ParamType: bool(*)(int, int)
    // cfcptr(func);
    cfref(func); // T: bool(int, int), ParamType: bool(&)(int, int)
    frref(func); // T: bool(&)(int, int), ParamType: bool(&)(int, int)
    cfrref(func); // T: bool(int, int), ParamType: bool(&&)(int, int)

    // 函数指针
    bool (*funcptr)(int a, int b);
    f(funcptr); // T: bool(*)(int, int), ParamType: bool(*)(int, int)
    fptr(funcptr); // T: bool(int, int), ParamType: bool(*)(int, int)
    fref(funcptr); // T: bool(*)(int, int), ParamType: bool(*&)(int, int)
    cf(funcptr); // T: bool(*)(int, int), ParamType: bool(*)(int, int)
    // cfptr(funcptr);
    fcptr(funcptr); // T: bool(int, int), ParamType: bool(*)(int, int)
    // cfcptr(funcptr);
    frref(funcptr); // T: bool(&)(int, int), ParamType: bool(&)(int, int)
    // cfrref(funcptr);

    // 函数引用
    bool (&funcref)(int a, int b) = func;
    f(funcref); // T: bool(*)(int, int), ParamType: bool(*)(int, int)
    fptr(funcref); // T: bool(int, int), ParamType: bool(*)(int, int)
    fref(funcref); // T: bool(int, int), ParamType: bool(&)(int, int)
    cf(funcref); // T: bool(*)(int, int), ParamType: bool(*)(int, int)
    // cfptr(funcref);
    fcptr(funcref); // T: bool(int, int), ParamType: bool(*)(int, int)
    // cfcptr(funcref);
    frref(funcref); // T: bool(&)(int, int), ParamType: bool(&)(int, int)
    cfrref(funcref); // T: bool(int, int), ParamType: bool(&&)(int, int)

    return 0;
}
```

通过值传递参数，引用性会被忽略，顶层 const / volatile 会被忽略

数组名或函数名实参在不初始化引用的时候会退化为指针

## Item 7：区别使用 () 和 {} 创建对象

> ```cmake
> MAKE_CXX_STANDARD 14
> MAKE_CXX_FLAGS --fno-elide-constructors # 禁止返回值优化
> ```
> 不考虑右值、移动等情况

### 聚合类

- C++ 11

  - 所有成员都是 `public` 
  - 没有类内初始化（C++17 取消）
  - 没有定义任何构造函数
  - 没有基类，没有虚函数

- C++ 17 修正

  - 可以类内初始化

  - 可以有基类（基类可以不是聚合类），但必须是共有继承，且必须是非虚继承

  - 总是假设基类是一种在所有数据成员之前声明的特殊成员，所以可以省略 `{}` 

    ```cpp
    class B: public std::string {
    public:
        int index = 0;
    };
    B{"test", 1};
    B{{"test"}, 1};
    ```

### 列表初始化

```cpp
class A {
public:
    A(int a) {
        std::cout << "int a" << std::endl;
    }

    A(const A& a) {
        std::cout << "const int& a" << std::endl;
    }
};

A a = 10; // 1. 一次构造，一次拷贝
A a(10); // 2. 只有一次构造，类内初始化不可使用这种方式，会解析为函数
A a = (10); // 3. 与 1 等价
A a{10}; // 4. 只有一次构造
A a = {10}; // 5. 只有一次构造
```

存在的问题：

- 对于 `A a = 10` 这种写法，不能接受多个参数，且要额外执行一次拷贝

- 对于 `A a(10)` 这种写法，被用作函数参数或返回值时还是会额外执行拷贝

  ```cpp
  void func(A arg) {}
  A funcr() { return A(10); }
  func(A(10)); // 一次构造，一次拷贝
  funcr(); // 一次构造，一次拷贝
  A aa = funcr(); // 一次构造，两次拷贝
  ```

列表初始化的优势

- 解决上面存在的问题

- 不允许缩窄转换，如从 `double` 转为 `int` （此前的写法允许缩窄转换）

- 大大简化了聚合类的初始化

- 对于解析问题天生免疫

  ```cpp
  void f(double value) {
    	int i(int(value));
  }
  ```

  这里的 `i` 有两种解析方式（C++会解析为函数声明）：

  - `int` 型变量
  - 返回值为 `int` 的函数声明（C++允许在函数声明时参数被多余的括号包裹）

数组的列表初始化

```cpp
class S {
  	int a;
  	int b;
};

std::array<int, 3> a1{1, 2, 3};
S a2[3] = {{1, 2}, {3, 4}, {5, 6}};
S a3[3] = {1, 2, 3, 4, 5, 6}; // 聚合类可以被自动解析
std::array<S, 3> a4{{{1, 2}, {3, 4}, {5, 6}}}; // std::array 内部为一个聚合类，多一层列表初始化
std::array<S, 3> a2{1, 2, 3, 4, 5, 6}; // 自动解析只发生在只有一层列表初始化时，迷惑性强，不建议写
```

如何让一个容器支持列表初始化

> `std::vector<int> a{1, 2, 3, 4};` 支持传入任意数量的参数 

- 通过 `std::initializer<>` 

```cpp
class A {
public:
    A(int a) {
        std::cout << "int a" << std::endl;
    }

    A(const A& a) {
        std::cout << "const int& a" << std::endl;
    }
  
  	A(int a, double b) {
      	std::cout << "int, double" << std::endl;
    }

    A(std::initializer_list<int> a) {
        std::cout << "initializer list" << std::endl;
        for (const int* item = a.begin(); item != a.end(); item++) {}
    }
};
```

- 列表初始化的优先级问题：除非万不得已，否则一定会优先匹配 `initializer_list` 
  - 上面例子中的第一个方法将永远不会被匹配到
  - 调用 `A(1, 2.0)` 时，第三个方法也不会被匹配到，因为 2.0 可以被隐式转换为 `int` ，并且由于列表初始化不允许缩窄转换，这里调用时会报错
  - 只有无法隐式转换的时候（例如 `std::string` 到 `int` ），列表初始化才会匹配其他构造函数
  - 使用 `()` 初始化不会遇到优先级问题（因为不可能调用到 `initializer_list` ）

- 空列表 `{}` 不会调用 `initialize_list` 

## Item 2：理解 auto 类型推导

万能引用的另一种写法：

```cpp
auto &&
```

列表初始化的类型推导

```cpp
auto a1 = 10; // auto: int
auto a2(10); // auto: int
auto a3{10}; // auto: int，在 14 年修改 C++ 标准之前，这里会被推导为 std::initializer_list<int>
auto aerror{10, 20} // Error: 原因如上，这里不会被推导为 std::initializer_list<> 了
auto a4 = {10}; // std::initializer_list<int>
```

列表初始化的模版类型推导

```cpp
template<typename T>
void func(std::initializer<T> a);
// Error: void func(T a); 模版无法被推导为 initializer list
func({1, 2, 3});
```

在 C++14 之后，`auto` 可以作为返回值，推导规则与模版的推导规则相同

## Item 9：优先考虑别名声明而非 `typedef` 

`typename` 关键字

- 用来澄清模版内部的一个标识符代表的是某种类型

- 当编译器遇到 `T::xxx` 类似的语法时，在实例化之前编译器都无法确定作用域运算符后的是数据成员还是类型成员，但为了处理模版，编译器需要对此进行区分。默认情况下作用域运算符后都跟数据成员，当跟类型成员时，需要使用 `typename` 关键字说明

  ```cpp
  struct Test1 {
      int SubType;
  };
  int Test1::SubType = 0; // 必须在外面定义
  
  struct Test2 {
      typedef int SubType;
  };
  
  template<typename T>
  class A {
  public:
      void func() {
          T::SubType; // 数据成员
          typename T::SubType a; // 类型成员
      }
  };
  
  int main() {
    	A<Test1> a;
  }
  ```

对于模版来说，`using` 比 `typedef` 更好用

```cpp
// using
template<typename T>
using MyVector = std::vector<T>

template<typename T>
class A {
public:
  	void func() {
      	MyVector<T> mv;
    }
}

// typedef
template<typename T>
struct MyVector {
		typedef std::vector<T> type;
}

template<typename T>
class A {
public:
  	void func() {
      	typename MyVector<T>::type mv;
    }
}
```

类型萃取器：用于添加/删除模版 T 的修饰

```cpp
#include <type_traits>

// 将 const T 转为 T
typename std::remove_const<T>::type // C++17
std::remove_const_t<T> // C++14
/* 	
template<class T>
using remove_const_t = typename std::remove_const<T>::type 
*/
```

## Item 23：理解 `std::move` 和 `std::forward` 

`std::move` 

- 实现

  ```cpp
  #include <type_traits>
  
  // C++11
  template<typename T>
  typename std::remove_reference<T>::type &&move(T&& param) {
    	using ReturnType = typename std::remove_reference<T>::type &&;
    	return static_cast<ReturnType>(param);
  }
  ```

- 实际做的事情

  - 转化实参为右值
  - 对于一个对象使用 `std::move` 就是告诉编译器这个对象 **很适合** 被移动

- 对于 `const` 右值引用，只能匹配到拷贝构造而非移动构造

`std::forward` 

- 有条件的 `std::move` ，当实参用右值初始化时才将其转为右值

## Item 3：理解 `decltype` 类型推导

`decltype` + 变量

```cpp
int a = 10;
decltype(a) b; // 仅仅作用域 a 对象（变量），b: int
```

- 所有信息都被保留
  - 包括顶层 const、右值引用等
  - 数组和函数也不会退化

`decltype` + 表达式

``` cpp
int a = 10;
decltype((a)) b; // 作用于 (a) 这个表达式，b: int&
```

- 返回表达式结果对应的类型
  - 表达式结果为左值：返回该类型的左值引用
  - 表达式结果为右值：返回该类型

`decltype` 并不会计算表达式的值，编译器会分析器表达式并得到其类型（编译期的动作）

`decltype` 的使用场景

- 某些情况下模版函数的返回类型是无法提前得到的，例如 `std::vector<bool>` 

  - C++11 的写法：尾置返回值类型

    ```cpp
    template<typename Container, typename Index>
    auto func(Container &c, Index i) -> decltype(c[i]) {
      	// do something
      	return c[i];
    }
    ```

  - C++14 之后，auto 可以作为返回值类型，但是这里仍然需要使用尾置返回值类型的写法：

    这里如果不使用尾置返回值类型的写法会导致：

    - auto 遵循模版类型推导
    - `c[i]` 推导出的引用性被忽略
    - 而 `decltype` 可以保留所有信息，引用性同样被保留
