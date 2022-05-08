## 哈希

- 手写hash函数时：`hash(x) = x % p` 中的p需为素数
- p称为哈希表的容量，总数除以p称为哈希表的负载因子

### 字符串哈希

```cpp
for (int i = 1; i < n; i++)
    res = (res * base + (s[i] - 'a')) % p
```

- $c_i$是一个与$s_i$有关的数
- base是一个自己指定的数，一般是一个大于字符集中字符数量（$c_i$的最大值）的素数
- 9999971, 1e9 + 7

- 利用前缀和的思想快速得到任意一段s的子串的哈希值
  - 用数组a记录计算hash的中间过程，则有a[i] = hash($s_1s_2···s_i$)
  - 则子串hash值为

- 通常写双哈希就够用

```cpp
int calc(int l, int r)
{
    int t = a[l - 1] * pow(base, r - l + 1) % p; // 实际做的时候用一个数组记录base的幂，防止溢出
    return (a[r] - t + p) % p; // + p防止为负
}
```

### STL

- [unordered_map<key, value>](http://www.cplusplus.com/reference)

### 二维数组哈希

- 对于n行m列的数组，对于i, j位置的数，hash += pow(base, (i - 1) * m + j - 1)
- 状态压缩

## 堆

### STL(priority_queue)

- 跟手写堆类似的工具，但只能修改队首的元素

- 修改堆中间的元素需要手写堆并维护一个位置数组

- 大根堆`priority_queue<int> q;` `priority_queue<int, vector<int>, less<int>> q;`

- 小根堆`priority_queue<int, vector<int>, greater<int> > q;`

## 字典树Trie

Trie是一种存储字符串的树形数据结构，除了根节点，每个节点可以存储一个字符，从根节点到书上某一节点的路径代表一个字符串，如果一个字符串在某个结点结束，则给这个结点打上一个结束标记

```cpp
const int maxn = 10000;  // 所有字符串的长度之和
const int charsize = 26; // 字符集大小

int nxt[maxn + 1][charsize], cnt = 0;

bool leaf[maxn + 1];

void insert(char s[], int len) {
    int now = 0;
    for (int i = 1; i <= len; i++) {
        int x = s[i] - 'a';
        if (!nxt[now][x]) {
            // cnt表示目前除了根节点之外还有几个点，新建一个点 cnt+1
            nxt[now][x] = ++cnt;
        }
        now = nxt[now][x];
    }
    leaf[now] = 1;
}

bool find(char s[], int len) {
    int now = 0;
    for (int i = 1; i <= len; i++) {
        int x = s[i] - 'a';
        if (!nxt[now][x]) {
            return false;
        }
        now = nxt[now][x];
        return leaf[now];
    }
}

```