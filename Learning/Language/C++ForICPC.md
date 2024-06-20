# 从 $C++98$ 到 $C++20$


+ 选取 OI 中可能用到的，但比较冷门的语法、函数。
+ 以版本为线进行了梳理
+ 实用至上，尽量少地探究语法背后的本质。
+ 我转载的，[原文](https://www.luogu.com.cn/blog/AccRobin/grammar-candies)，作者：@ Acc_Robin
## 目录
### $C++98$
+ $algorithm$ 库	
   ###### 一些常见且比较重要的函数
	###### 一些比较冷门的函数
	###### $GNU$ 私货
+ $numeric$ 库
+ $functional$ 库
+ $cmath$ 库
+ $\_\_builtin$ 家族
### $C++11$
+ 零零散散的语法糖
	###### $auto$
	###### $lambda$ 表达式
	###### $range-for$
+ $STL$
	###### $emplace$
	###### $shrink\_to\_fit$
+ $algorithm$ 库
+ $numeric$ 库
+ $iterator$ 库
+ $functional$ 库
+ $random$ 库
+ $cmath$ 库
### $C++14$
+ 零零散散的语法糖
	###### $auto$
+ $functional$ 库
### $C++17$
+ 零零散散的语法糖
	###### 结构化绑定
	###### 类模板的实参推导
	###### $if$ 和 $switch$ 中进行初始化
	###### $using$ 多个名称
+ $STL$
	###### $set/map$ 的 $merge$
+ $algorithm$ 库
+ $numeric$ 库
+ $iterator$ 库
+ $cmath$ 库
### $C++20$
+ 零零散散的语法糖
	###### 三路比较运算符
	###### $range-for$ 的初始化语句和初始化器
	###### 规定有符号整数以补码实现
+ $STL$
+ $bit$ 库
+ $ranges$ 库
+ $numbers$ 库
## $C++ 98$
#### $algorithm$ 库
$algirithm$ 中有大量的函数，这些函数都位于命名空间 $std$ 中。

最常见的有 $max/min、swap、sort、unique/lower\_bound/upper\_bound、reverse$。

一些常见且比较重要的函数：
+ $find(bg,ed,val)$
	##### 返回指向第一个等于 $val$ 的元素的指针。
	##### 时间复杂度$O(n)$。后文所有序列操作的函数，都以 n代指$ed-bged−bg$。
+ $fill(bg,ed,val)$
	##### 将 $[bg,ed)$之间的所有元素复制为 $val$。
	##### 复杂度为 $O(n)$，常数略大于$memset$。
	##### 在 $val=0/-1/\texttt{0x3f}$时常数与$memset$相同。
	##### 常用于弥补 $memset$ 无法赋值的问题，如赋值一个数组为$1$。

+ $copy(bg1,ed1,bg2)$
	##### 将$[bg_1 ,ed_1)$ 中的元素复制到$bg_2$
	##### 复杂度$O(n)$。

+ $stable$$_$$sort(bg,ed)$
	##### 对$[bg,ed)$进行 **稳定** 排序。
	##### 时间复杂度$O(nlogn)$，要$O(n)$的额外空间。
	##### 当空间不足时使用$O(nlog^2n)$的双调排序。

+ $nth\_element(bg,md,ed)$：
	##### 将$[bg,ed)$中的内容重新分配顺序，小于（等于） $md$ 的元素在$[bg,md)$，大于（等于） $md$ 的元素都在 $(md,ed)$。
	##### 时间复杂度 $O(n)$，需要 $O(n)$的额外空间。
	##### 第四个参数为比较函数，若不传则默认$ less<>()$。
	##### 常用于线性求序列中的第 $k$大，常用于实现替罪羊树。

+ $max\_element/min\_element(bg,ed)$
	##### 返回指向 $[bg,ed)$中最大$ / $最小的元素的指针。
	##### 时间复杂度 $O(n)$。
	##### 第三个参数可传入比较函数。
	##### 求数组最大值就可以直接写：$max\_element(a+1,a+n+1)$

+ $random\_shuffle(bg,ed)$
	##### 打乱$[bg,ed)$中元素的顺序。
	##### 时间复杂度$O(n)$。
	##### 第三个参数传入一个函数 $func(int n)$，这个函数的返回值是一个 $[1,n]$中的随机整数。
	##### 在未传入第三参数时，若 $ed-bg>\texttt{RAND\_MAX}$那么 **其随机性将无法保证**。
	##### 在 $C++14$ 中被弃用，在 $C++17$ 中被废除，$C++11$ 之后都应当以 $shuffle$ 替代之。
+ $next\_permutation(bg,ed)$
	##### 将$[bg,ed)$更改为下一个排列，并返回$1$。
	##### 若$[bg,ed)$已经是最后一个排列，那么返回$0$。
	##### 下一个排列的定义为字典序严格大于当前排列的下一个排列。
	##### 时间复杂度$O(n)$。
   ##### $prev\_permutation(bg,ed)$可以求出上一个排列。
	##### 事实上$[bg,ed)$不一定要是排列，可以存在相同元素。
	#### 常用于枚举全排列：
```cpp
	iota(p,p+n,0);
	do{
 	//do something   
	}while(next_permutation(p,p+n));
```
+ 一些比较冷门的函数
	+ $merge(bg_1,ed_1,bg_2,ed_2,bg_3)$
		##### $[bg_1,ed_1)$和$[bg_2,ed_2)$是两个有序序列，对其进行归并并存入$bg_3$

		##### 不能够原地归并，若要原地归并请使用 $inplace\_merge$。
		##### 时间复杂度 $O(ed_1-bg_1+ed_2-bg_2)$
		##### 可以传入第六参数作为比较函数。
	+ $inplace\_merge(bg,md,ed)$
		##### 将$[bg,md)$和$[md,ed)$归并排序，并存入$bg$。
		##### 时间复杂度$O(n)$，需要$O(n)$的额外空间。
		##### 当空间不足时使用$O(nlogn)$的原地排序。
		##### 常数较小，可能比手写的还快。
		##### 可以传入第四个参数作为比较函数。
		##### 常用于$CDQ$分治等分治算法，非常好用。

	+ $count(bg,ed,val)$
		##### 返回$[bg,ed)$中等于$val$的元素的个数。
		##### 时间复杂度$O(n)$
	
   + $count\_if(bg,ed,func)$
		##### 返回$[bg,ed)$中使得函数$func$返回值为$true$的元素的个数。
		##### 时间复杂度$O(n\times f)$,$ff$为$func$的复杂度。
		##### 常用的$func$有：$islower/isupper/isdigit$ 等。
	+ $replace(bg,ed,val_1,val_2)$
		##### 将$[bg,ed)$中所有等于$val_1$的元素替换为$val_2$
		##### 时间复杂度$O(n)$。
	+ $for\_each(bg,ed,func)$
		##### 对$[bg,ed)$中所有元素执行函数$func$。
		##### 时间复杂度$O(n\times f)$。
		##### 其实没啥用，就是能压行。
	+ $transform(bg_1,ed_1,bg_2,bg_3,func)$

		##### 对$[bg_1,ed_1)$和$[bg_2,bg_2+ed_1-bg_1)$中的元素依次执行二元函数$func$，并将返回值存入$bg_3$ 
		##### 时间复杂度$O(n\times f)$。
	
   + $rotate(bg,md,ed)$
		##### 将$[bg,ed)$循环至$md$处元素位于$bg$。
		##### 时间复杂度$O(n)$
		##### 例子：
``` cpp
	vector<int>a={1,2,3,4,5};
	rotate(a.begin(),a.begin()+1,a.end());
	//a={2,3,4,5,1}
	vector<int>b={1,2,3,4,5};
	rotate(b.rbegin(),b.rbegin()+1,b.rend());
	//b={5,1,2,3,4}
```
#### $GNU$ 私货
有一些以双下划线开头的函数并未在 $C++$ 标准中，是 $GNU$ 的私货，在 $NOI$ 系列赛事中可以使用。

+ $__lg(x)$
	##### 返回$\lfloor \log_2x\rfloor$
	##### 时间复杂度$O(1)$。
	##### 常用于实现倍增、二进制运算等。
+ $__gcd(x,y)$
	##### 返回$\gcd(x,y)$。
	##### 复杂度是对数级别的，常数较小。
	##### 注意，返回值的符号 **不一定** 是正。
	##### 在 $C++17$ 之前都是很常用的。

#### $numeric$ 库
这里的函数，真的很好用。
+ $accumulate(bg,ed,val)$
	##### 将$[bg,ed)$中的所有所有元素与初始值$val$相加，返回这个和。
	##### 时间复杂度$O(n)$。
	##### 可以传入第四个参数作为加法。
	##### 可以用于求序列和，但注意，该函数返回值与$val$类型一致，意味着你要注意$long long$的问题：
``` cpp
	accumulate(bg,ed,0);//返回值是 int，可能溢出
	accumulate(bg,ed,0ll);//返回值是 long long
```	
+ $inner\_product(bg_1,ed_1,bg_2,val)$
	##### 将$[bg_1,ed_1)$和$[bg_2,bg_2+ed_1-bg_1)$对应位置一一相乘再与初始值$val$相加，返回这个和。
	##### 时间复杂度$O(n)$。
	##### 可以传入第五、六个参数分别作为加法和乘法。
	##### 用于做向量内积。
+ $partial\_sum(bg_1,ed_1,bg_2)$
	##### 对$[bg_1,ed_1)$做前缀和并存入$[bg_2,bg_2+ed_1-bg_1)$
	##### 时间复杂度$O(n)$。
	##### 可以传入第四个参数作为加法。
	##### 可以原地求前缀和。
+ $adjacent\_difference(bg_1,ed_1,bg_2)$
	##### 对$[bg_1,ed_1)$求差分并存入$[bg_2,bg_2+ed_1-bg_1)$
	##### 时间复杂度$O(n)$。
	##### 可以传入第四个参数作为减法。
	##### 可以原地差分。

#### $functional$ 库
常见的函数有$less<>/greater<>$等。

事实上，大部分运算 $/$ 比较也在这里：
```cpp
plus<>;//x+y
minus<>;//x-y
multiplies<>;//x*y
divides<>;//x/y
modulus<>;//x%y
negate<>;//-x

equal_to<>;//x==y
not_equal_to<>;//x!=y
greater<>;//x>y
less<>;//x<y
greater_equal<>;//x>=y
less_equal<>;//x<=y

logical_and<>;//x&&y
logical_or<>;//x||y
logical_not<>;//!x

bit_and<>;//x&y
bit_or<>;//x|y
bit_xor<>;//x^y
//注意 bit_not(~x) 是 C++14 的哦~
```
#### $cmath$ 库
+ $fabs(x)$
	##### 返回$|x|$。
	##### 注意，对浮点运算请都使用$fabs$而不是$abs，因为有可能你调用的是$abs(int)$。
+ $fmod(x,y)$
	##### 返回$x\bmod y=x-y\lfloor\frac xy\rfloor $
	##### 在一些三角函数的地方可能会用到对$\pi$取模。
+ $exp(x)$
	##### 返回$e^x$
	##### 在$double$内,$x$的有效区间为$[-708.4,709.8]$
+ $log(x)$
	##### 返回$\ln x$。
	##### 当$x\in (-\infty,0]$时报错。
	##### 对数家族还有：$log10(x)$和$log2(x)$。
	##### 请注意，$log2(x)$是$C++11$的。
+ $ceil(x)$
	##### 返回$\lceil x\rceil$
	##### 其返回值依旧是浮点类型，输出时注意格式。
+ $floor(x)$
	##### 返回$\lfloor x\rfloor$
	##### 其返回值依旧是浮点类型，输出时注意格式。
#### $\_\_builtin$家族
注意：这里的内容并不在$C++$标准中，全部都是$GNU$的私货，若使用其它编译器则可能无法通过编译。
+ $\_\_builtin\_popcount(x)$
	##### 返回$x$在二进制下$1$的个数。
	##### 时间复杂度$O(\log\log x)$
+ $\_\_builtin\_parity(x)$
	##### 返回$x$在二进制下$1$个数的奇偶性。
	##### 时间复杂度$O(1)$，快于$__builtin_popcount(x)&1$。
+ $\_\_builtin\_ffs(x)$
	##### 返回二进制下最后一个$1$是从后往前第几位。
	##### 时间复杂度$O(1)$。
+ $\_\_builtin\_ctz(x)$
	##### 返回二进制下后导零的个数，$x=0$时$UB$。
	##### 时间复杂度$O(1)$。
+ $\_\_builtin\_clz(x)$
	##### 返回二进制下前导零的个数，$x=0$时$UB$。
	##### 时间复杂度$O(1)$。
## $C++ 11$
从 $C++98$ 到 $C++11$ 是一次重大的飞跃，许许多多非常实用的函数与语法如雨后春笋般出现。

#### 零零散散的语法糖
##### $auto$
$auto$ 在 $C++98$ 中是一个较偏僻冷门的东西，因此在$C++11$中直接将其抛弃，并赋予其新生。

+ $auto$可以用来声明一个变量，其类型由初始化的内容定义。
```cpp
auto a=1;//a is int
auto b=2.0;//b is double
set<int>s;
auto it=s.end();//it is set<int>::iterator
```
因此$auto$声明变量时必须有初始化内容，否则将$CE$。

同时，也可以声明为其它变量的引用：
```cpp
auto x=true;//x is bool
auto&y=x;//y is reference of x
y=false;
if(x)
  throw;//will not run
```
常用于声明一些类型名很长的变量，如:$set<pair<int,int>,greater<pair<int,int>>>::iterator$
+ $auto$用于声明有固定返回值类型的函数，在$C++11$时需要尾随返回类，但在$C++14$及之后就不需要了：
```cpp
auto func(double x)->double{
return x*2-1;
}//C++11

auto func2(double x){
return x*2-1;
}//C++14
```
+ 也可以用来声明一个$lamda$函数，见下文$lambda$表达式 部分。

##### $lambda$ 表达式
$lambda$ 相当于一个函数，其形式多变，但都是由若干部分组成：

$[captures](params)->T\left \{\begin{matrix}body \end{matrix}\right\} $

其中$captures$填捕获的方式，$params$填传入的参数，$T$填返回值类型，$body$就是函数主体。

+ $captures$

有两种填法： $&$ 和 $=$ ，不填时，局部的$lambda$将不会进行捕获，全局的$lambda$默认为 $&$。

$&$ 表示这个表达式捕获的内容是引用的形式，而 $=$ 表示捕获的内容是复制且只读的。
```cpp
int x=1;
[=](){x=2;}();//CE,向只读变量‘x’赋值
[&](){x=2;}();//OK,x will be 2
//上面 lambda 最后的括号是对其进行调用
```
这里有坑：请尽量使用 $&$，考虑如下程序片段：
```cpp
vector<int>v(n),o(n);
for(int&x:v)cin>>x;
iota(o.begin(),o.end(),0);
sort(o.begin(),o.end(),[=](int x,int y){return v[x]<v[y];});
```
其作用是按 $v$ 的大小对其下标$o$排序，但注意使用的是$=$，这意味着每次调用 $lambda$ 时都将$v$拷贝了一份，一共拷贝 $n\log n$ 次，直接 $TLE$。

+ $params$

和普通函数一样。

+ $T$

若此处省略，则其返回值将为 $auto$ ：
```cpp
[](int x){return x*2.0;}(3);//will return double 6.0
```
也可使用$auto$将$lambda$表达式作为一个可调用的函数：
```cpp
auto sqr=[](double x){
    return x*x;
};
```
那么每次调用 $sqr(r)$ 都将返回 $r\times r$ 的值。

这样写的函数将自带 $inline$ ，比写 $inline$ 短多了。

+ $range-for$
$for$循环中轻松地遍历容器（$vector、set、list$等）：
```cpp
vector<int>v={5,1,3,4,2};
for(int x:v)cout<<x<<' ';
//output:5 1 3 4 2
//按顺序遍历 v 中的每一个元素，并赋值给 x。
```
也可以将$x$声明为引用：
```cpp
vector<int>v(n);
for(int&x:v)cin>>x;
//读入一个长度为 n 的序列
```
注意， $x$ 的类型必须与 $v$ 中元素的类型保持一致，否则会 $CE$ 。

也可以使用 $auto$ 进行声明。

注意，若遍历数组，那将从头到尾遍历一遍，不推荐。

用处极为广泛，常用于对于 $vector$ 存图的遍历等。

#### $STL$
##### $emplace$
在很多 $STL$ 容器中都出现了一个新的函数—— $emplace$ ，如：
```cpp
set<int>s;
s.insert(1);//C++98
s.emplace(1);//C++11

queue<int>q;
q.push(2);//C++98
q.emplace(2);//C++11

vector<int>v;
v.push_back(3)//C++98
v.emplace_back(3);//C++11

deque<int>dq;
dq.push_front(4)//C++98
dq.emplace_front(4);//C++11
```
$emplace$ 相比原先的 $insert/push/push\_back/push\_front$ 区别是， $emplace$ 通过调用元素的构造函数来进行插入，所以它会比之前的函数更快一些。

因此也产生了使用上的区别：
```cpp
set<pair<int,int>>s;
s.insert(make_pair(1,2));//C++98
s.emplace(1,2);//C++11
```
更加便于书写。

但这要求用户自己的类型必须含有构造函数：
```cpp
struct A{
    int x;
};
queue<A>q;
q.emplace(1);//CE，A 没有构造函数

struct B{
    int x;
    B(int _x=0):x(_x){}
};
queue<B>p;
p.emplace(1);//OK，B 有构造函数
```
##### $shrink\_to\_fit$
$vector/deque/string/basic\_string$ 的 $shrink\_to\_fit$ 可以使其 $capacity$ 调整为 $size$ 的大小，如：
```cpp
vector<int>v={1,2,3};
cout<<v.size()<<' '<<v.capacity()<<'\n';
v.clear();
cout<<v.size()<<' '<<v.capacity()<<'\n';
v.shrink_to_fit();
cout<<v.size()<<' '<<v.capacity()<<'\n';
/*
output:
3 3
0 3
0 0
*/
```
常用于 $clear()$ 之后释放内存。

#### $algorithm$ 库
+ $shuffle(bg,ed,gen)$
	##### 打乱$[bg,ed)$的顺序，$gen$ 是一个随机数生成器$（mt19937）$。
	##### 时间复杂度$O(n)$。
	##### C++11 之后请尽量使用 $shuffle$ 而不是 $random\_shuffle$
+ $is\_sorted(bg,ed)$
	##### 判断 $[bg,ed)$ 是否升序排序。
	##### 时间复杂度 $O(n)$ 。
+ $minmax(a,b)$
	##### 返回一个$pair<>$，其$first$为$\min(a,b)$，$second$为$\max(a,b)$。
	##### 时间复杂度$O(1)$
	##### 常用于无向图存边的去重问题。
+ $max(l)/min(l)$
	##### $l$是一个初始化列表，这个函数返回$l$中最大$/$最小的元素。
	##### 时间复杂度$O(size_l)$
	##### 在多个元素求最大$/$最小时非常好用：$max({a,b,c})$
+ $minmax(l)$
	##### $l$是一个初始化列表，这个函数返回一个$pair<>$，其$first$为$l$中最小的元素，$second$为$l$中最大的元素。
	##### 时间复杂度$O(size_l)$
	##### 若要求一个序列$/$容器中最小和最大的元素，请使用$minmax\_element$。
+ $minmax\_element(bg,ed)$
	##### 返回一个$pair<>，其$first$为$[bg,ed)$中最小的元素，$second$为$[bg,ed)$中最大的元素。
	##### 时间复杂度$O(n)$
#### $numeric$库
+ $iota(bg,ed,val)$
	##### 将$[bg,ed)$中的元素依次赋值为 $val,val+1,val+2,\cdots$
	##### 时间复杂度$O(n)$
	##### 常用于给并查集初始化。
#### $iterator$库
+ $prev(it)/next(it)$
	##### 返回迭代器$it$的前驱$/$后继。
	##### 复杂度与$++/--$的复杂度相同，取决于容器。
	##### 可以更方便的实现许多内容：
```cpp
	set<int>s={1,2,3,4,5};
	auto i=s.lower_bound(3);
	++i;
	auto j=i;
	--i;
	//这是很麻烦的
	auto j=next(i);//很方便
```

+ $begin(container)/end(container)$
	##### 返回容器$\texttt{container}$的$begin()$和$end()$
	##### 复杂度取决于容器。
	##### 作用就是相比原先要短一个字节：
```cpp
set<int>t;
auto i=t.begin();
auto i=begin(t);//你比一比谁更短
```
#### $functional$ 库
+ $function$

声明方式：$function<R(Args...)>f$;

其中 $R$ 为返回值，$Args...$ 为形参， $f$ 为名称。

一个 $function$ 可以作为函数直接使用。
```cpp
function<int(int,int)>f[4]={
[](int x,int y){return x+y;},
[](int x,int y){return x-y;},
[](int x,int y){return x*y;},
[](int x,int y){return x/y;}
};
//声明一个数组，每个元素都是一个 function<int(int,int)>

for(int i=0;i<4;++i)
  cout<<f[i](5,2)<<' ';
//output:7 3 10 2
```
常用来代替函数指针。

#### $random$ 库
用于代替垃圾的 $rand$。

+ $mt19937$

	##### 一个类型，作为随机数生成器。
	##### 其构造函数应传入一个数字作为随机种子，使用时用法和 $rand$ 相同。
	##### 生成 $unsigned int$ 范围内的随机数。
```cpp
mt19937 gen(123456);//123456 为随机种子
int x=gen()%10000;//x will in [0,10000)
uint32_t y=gen();//normally y will in [0,2^32)
```
随机种子通常为时间相关，下面的非常常用，建议背过
```cpp
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
//chrono 在头文件 <chrono> 中
```
+ $uniform\_int\_distribution<T>(L,R)$
	##### 随机数发生器，每次调用时传入一个 $mt19937$，返回一个 $[L,R]$之间的整数，类型为 $T$ ，若 $T$ 为空则默认为 $int$ 。
+ $uniform\_real\_distribution<T>(L,R)$
	##### 随机数发生器，每次调用时传入一个 $mt19937$ ，返回一个$[L,R]$之间的实数，类型为 $T$，若$T$为空则默认为 $double$ 。
```cpp
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<>dist(1,1000);
int x=dist(gen);// x is a random int in [1,1000]
uniform_real_distribution<>dist2(-10,10);
double y=dist2(gen);// y is a random double in [-10,10]
```
#### $cmath$ 库
+ $exp2(x)$
	##### 返回$2^x$ 
+ $log2(x)$
	##### 返回 $\log_2(x)$
+ $hypot(x,y)$
	##### 返回$\sqrt{x^2+y^2}$
	##### 常用于求两点之间的距离，非常方便。
+ NAN，INFINITY
	##### 两个$define$出的量，由编译器实现定义。
## $C++14$
### 零零散散的语法糖
+ 弃用了$register$。
#### $auto$
+ $auto$可以在$lambda$的形参中出现：
```cpp
void func(auto x){
  //do something
}
```
但注意，在普通函数中使用$auto$作为形参直到$C++20$才支持。

$auto$ 可以作为普通函数的返回值：
```cpp
auto sum(int x,int y){
	return x+y;
}
```
### $functional$ 库
+ $functional$ 库在 $C++14$ 给大部分模板都加入了默认类型 $void$ ，如：$greater<void>、plus<void>$等。

这里的 $void$ 可以省略，因此以后就可以不用写具体类型了：
```cpp
vector<pair<int,int>>v;
//...
sort(begin(v),end(v),greater<pair<int,int>>());//C++11
sort(begin(v),end(v),greater<>());//C++14
```
非常方便。

+ $bit\_not<>$

在 $C++98$ 的 $functional$ 库中有提到。

## $C++17$
### 零零散散的语法糖
结构化绑定
+ 从一个结构体$/$初始化列表中获取元素.
```cpp
pair<int,int>a=make_pair(1,2);
{
  int x,y;
  tie(x,y)=a;
}//C++11
{
  auto[x,y]=a;//结构化绑定
}//C++17
```
也可以声明为引用：
```cpp
struct A{
  int u,v,w;
}a;
auto&[x,y,z]=a;//结构体
x=1,y=2,z=3;
cout<<a.u<<' '<<a.v<<' '<<a.w<<'\n';
//output:1 2 3
```
+ 可以搭配 $range-for$ 使用：
```cpp
vector<pair<int,int>>v(n);
for(auto&[x,y]:v)cin>>x>>y;
```
+ 常用于带边权的图遍历：
```cpp
vector<pair<int,int>>G[N];
void dfs(int u,int fa){
for(auto[v,w]:G[u])if(v!=fa)
      dis[v]=dis[u]+w,dfs(v,u);
}
```
非常好用。
##### 类模板的实参推导
在使用类模板时不必写出具体的实参名：
```cpp
auto x=pair<int,double>(1,2.5);//C++11
auto y=pair(5,7.2);//C++17：推导了 pair<int,double>

vector<int>v={1,2,3};//C++11
vector w={1,2,3};//C++17：推导了 vector<int>
```
推导也可以嵌套，主要用于简化代码。

##### $if$ 和 $switch$ 中进行初始化
在 $if$ 语句和 $switch$ 语句中可以像 $for$ 循环一样加入初始化语句。
```cpp
cin>>n;
if(int x=f(n);x>=10)
  cout<<x<<'\n';
```
顺便提一句，在 $C++98$ 中就已经可以这样写了：
```cpp
if(int x=f(n))//if x is true then:
  //...
```
##### $using$声明多个名称
可以使用 $using$ 语句后跟一个逗号分隔的声明符列表。
```cpp
using std::cin,std::cout,std::cerr;
```
起到同时声明多个的作用。

对于不喜欢 $using\ namespace\ std$ 的同学比较有用。

### $STL$
+ $set/map$的$merge$
将一个 $set/map$ 并入另一个，若将 $t$ 并入 $s$ ，则所有 $t$ 中未在 $s$ 里出现的元素将被插入 $s$ ，并在 $t$ 中被删除。
```cpp
set<int>s={1,2,3};
set<int>t={3,4,5};
s.merge(t);
cout<<s.size()<<" : ";
for(int i:s)cout<<i<<' ';
cout<<'\n';
cout<<t.size()<<" : ";
for(int i:t)cout<<i<<' ';
/*
output:
5 : 1 2 3 4 5 
1 : 3 
*/
```
+ 对于 $s.merge(t)$，复杂度为 $O(|t|\log(|s|+|t|))$

### $algorithm$ 库
+ 以 $shuffle$ 替代 $random\_shuffle$ ，$random\_shuffle$ 完全被废除。

+ $sample(bg,ed,out,n,gen)$

	##### 从$[bg,ed)$中随机取出$n$个元素，输出到$out$迭代器中,随机数生成器为$gen$。
	##### 每个元素等将概率被选择。
	##### $out$的一个具体的例子是$back\_inserter$。
### $numeric$库
+ $gcd(x,y)/lcm(x,y)$
	##### 返回$\gcd(|x|,|y|)/ \operatorname {lcm}(|x|,|y|)$的值。
	##### 复杂度对数级别的。
	##### 保证了返回值的符号是正。
	#####  $lcm$ 的实现是先除后乘。
### $iterator$ 库
+ $size(container)/empty(container)$
	##### 返回一个容器的$size()$是否为空。
	##### 复杂度取决于容器。
+ $data(container)$
	##### 返回$container.data()$。
	##### 复杂度取决于容器。
### $cmath$库
+ 出现了一些比较谔谔的《数学特殊函数》，$OI$中应该不会用到，如果想了解请前往 [官网](https://en.cppreference.com/w/cpp/numeric/special_functions)。
+ $hypot(x,y,z)$
	##### 返回 $\sqrt{x^2+y^2+z^2}$
	##### 复杂度$O(1)$。
	##### 常用来求三维中两点距离。
## $C++20$
### 零零散散的语法糖
#### 三路比较运算符 $<=>$
新增运算符 $<=>$ 满足：

+ 若$a<b，则 (a<=>b) <0$。
+ 若$a>b，则 (a<=>b) >0$。
+ 若$a=b，则 (a<=>b) =0$。

重载此运算符后，就可以直接使用$<\ \ >\ \ <=\ \ >=$ 几种运算符，但请注意若要使用 $==$ 和 $!=$ 仍需再写一个函数：
```cpp
struct T{
 	int x,y;
 	T(int _x=0,int _y=0):x(_x),y(_y){}
 	auto operator<=>(const T&_)const{
  		return x-_.x;
	}
}a(1,3),b(2,4);

if(a<b)cout<<"a<b\n";//OK,output: a<b
if(a==b)cout<<"a==b\n";//CE not operator==
```
#### $range-for$的初始化语句和初始化器
在$range-for$前面可以加入一个初始化语句 $/$ 初始化器，可以是
+ 表达式语句（空语句）。
+ 声明语句（或结构化绑定）。
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
 	vector<pair<int,int>>v={{1,2},{3,4}};
 	for(int i=0;auto[x,y]:v)
  	cout<<(i++)<<" : ("<<x<<','<<y<<")\n";
}
/*
output:
0 : (1,2)
1 : (3,4)
*/
```
更便利了捏~

#### 规定有符号整数以补码实现
谔谔，谔谔。

终于可以写什么 $&-2$ 这种东西了，好耶！

### $STL$
#### $contains$
在$set/map/multiset/multimap$中查找一个元素是否存在，如果使用$count$那么复杂度关于出现次数是线性的，这不好。 $C++ 20$ 中加入的 $contains$的复杂度是$O(\log )$的，返回值是$true/false$，非常好用。

#### $bit$ 库
C++20 加入的新库，头文件 <bit>。

+ $popcount(x)$

	##### 返回 无符号整形$x$在二进制下$1$的个数。
  	##### 时间复杂度$O(\log\log x)$
	##### 使用$__builtin_popcount$实现，但会检查传入的参数是否为无符号整形。
```cpp
unsigned int x=3;
cout<<popcount(x)<<'\n';//OK, output:2
int y=7;
cout<<popcount(x)<<'\n';//CE, y is not unsigned 
double z=2.5;
cout<<popcount(x)<<'\n';//CE, z is not integer
```
下述$bit$库中的函数也都会进行这个检查。

  
```cpp
countl_zero(x);//从最高位起连续的 0 的数量
countr_zero(x);//从最低位起连续的 0 的数量
countl_one(x);//从最高位起连续的 1 的数量
countr_one(x);//从最低位起连续的 1 的数量
```
上述函数的复杂度都是 $O(1)$。

+ $rotl(x)/rotr(x)$
	##### 返回$x$二进制下逐位向左$/$右旋转得到的结果。
	##### 复杂度$O(1)$。

+ $bit\_width(x)$

	##### 当$x=0$时返回$0$，否则返回$1+\lfloor \log_2(x) \rfloor$
	##### 即二进制下$x$的位数。
	##### 复杂度$O(1)$。
+ $bit\_floor(x)/bit\_ceil(x)$
	##### 返回不超过$x$的最大的$2$的整次幂$/$不小于$x$的最小的$2$的整次幂。
	##### 复杂度$O(1)$。
+ $has\_single\_bit(x)$
	##### 返回$x$是否为$2$的整次幂，相当于$popcount(x)==1$。
	##### 复杂度$O(1)$。
#### $ranges$库
$C++20$加入的库，提供了各种处理元素范围的组件，在头文件 <ranges> ，命名空间 $std::ranges::views$或$std::views$中。

在 ranges 库中的一个函数 func ，其通常有两种形态：$ranges::func\_view$ 和 $views::func$，下文我们将全部选择更简短的后者。

+ $view$ 是一个指定范围的视图，可以在 $O(1)$ 时间内完成移动 $/$ 复制 $/$ 赋值。

这里的描述很不优美，如果看不懂描述可以直接看代码部分。

+ $empty()$

	##### 一个空的 $view$。
+ $single(val)$

	##### 一个只有 $val$ 的 $view$。
+ $iota(bg,ed)$

	##### 由 $[bg,ed)$ 之间所有自然数组成的 $view$。
  	##### 若省略$ed$则为一个无限长的序列。

	##### 可以搭配下文的 $take $一起使用。
```cpp
for(int i:views::iota(1,6))
 cout<<i<<' ';
//output:1 2 3 4 5
```
+ $all(v)$

	##### 包含$v$所有元素的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::all(v))
 	cout<<i<<' ';
//output: 1 2 3 4 5
```
+ $transform(v,func)$

	##### 对$v$ 中每个元素执行 $func$ 后的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::transform(v,[](int x){return x*2-1;}))
 	cout<<i<<' ';
//output:1 3 5 7 9
```
+ $take(v,n)$

	##### $v$ 的前 $n$ 个元素组成的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::take(v,3))
 cout<<i<<' ';
//output:1 2 3
```
+ $take\_while(v,func)$

	##### $v$ 的起始元素到首个使得 $func$ 返回 $false$ 为止的元素组成的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::take_while(v,[](int x){return x<=3;}))
 	cout<<i<<' ';
//output:1 2 3
```        
+ $drop\_while(v,func)$

	##### 跳过直到第一个使得 $func$ 返回 $false$ 的元素后，剩余元素组成的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::drop_while(v,[](int x){return x<=3;}))
 	cout<<i<<' ';
//output:4 5 
```
+ $drop(v,n)$

	##### $v$ 的从第 $n+1$ 个元素开始到结束（跳过前 $n$ 个）的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::drop(v,3))
 	cout<<i<<' ';
//output:4 5
```
+ $reverse(v)$

	##### 翻转 $v$ 的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::reverse(v))
 	cout<<i<<' ';
//output:5 4 3 2 1
```
+ $filter(v,func)$

	##### 使得 $func$ 返回值为 $true$ 的元素的 $view$。
```cpp
vector v={1,2,3,4,5};
for(int i:views::filter(v,[](int x){return x&1;}))
 	cout<<i<<' ';
//output:1 3 5
```
+ 可以使用运算符 $|$ 连接两个或多个范围适配器：
```cpp
vector v={1,2,3,4,5};
for(int i:v|views::reverse|views::take(3))
	cout<<i<<' ';
//output:5 4 3

auto odd=[](int x){return x&1;};
auto sqr=[](int x){return x*x;};
for(int i:v|views::filter(odd)|views::transform(sqr))
//output:1 9 25
```
注意，这里的 | 是从左向右结合的：
```cpp
vector v={1,2,3,4,5};
using views::take,views::drop;

for(int i:v|take(3)|drop(1))
	cout<<i<<' ';
//output:2 3

for(int i:v|drop(1)|take(3))
	cout<<i<<' ';
//output:2 3 4
```
### $numbers$ 库
头文件 <numbers>，命名空间 $std::numbers$中提供了大量的数学常数：

![](https://cdn.luogu.com.cn/upload/image_hosting/af1dyd7h.png?x-oss-process=image/resize,m_lfit,h_544,w_720)

  这些都是类模板，调用时请填入类型：
```cpp
#include<numbers>
#include<iomanip>
#include<iostream>
int main(){
  std::cout<<std::fixed<<std::setprecision(9)<<std::numbers::pi_v<double><<'\n';
}
```
去掉末尾的 $_v$ 后直接就是一个常量：
```cpp
cout<<numbers::e<<'\n';
```
  