> writer: VenusHui
>  
> time: 2021.09.15
>
> last edit: 2023.01.13
>  
> Reference: 

[TOC]

# 基本算法

## 排序

### 快速排序

```cpp
void quick_sort(vector<int>& a, int l, int r) {
    if (l == r) return;
    int x = a[l + r >> 1]; // 选取 partition 的方式
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x); // 注意这里是小于而不是小于等于
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
    return;
}
```

### 归并排序

```cpp
void merge_sort(vector<int>& a, int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    // i 循环原始数组，j 循环 tmp 数组
    for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
    return;
}
```

## 二分

- **最大化最小 / 最小化最大** 问题通常用二分求解

```cpp
int l = 0, r = n - 1;
while (l < r) {
    int m = l + r >> 1; // 是否 +1 与区间的更新方式有关
    if (check(m)) l = mid + 1;
    else r = mid;
}
return l;
```

```cpp
int l = 0, r = n - 1;
while (l < r) {
	int m = l + r + 1 >> 1; // 是否 +1 与区间的更新方式有关
	if (check(m)) l = mid;
	else r = mid - 1;
}
return l;
```

## 高精度

- 高精度加法

```cpp
string add(string s1, string s2) {
    string ans;
    int t = 0, i = s1.size() - 1, j = s2.size() - 1;
    while (t || i >= 0 || j >= 0) {
        t += i >= 0 ? s1[i] - '0' : 0;
        t += j >= 0 ? s2[j] - '0' : 0;
        ans += t % 10 + '0';
        t /= 10;
        i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```

- 小于等于 `n` 进制高精度加法

```cpp
// 小于等于36进制高精度加法板子
char getChar(int n) {
    if (n <= 9)
        return n + '0';
    else
        return n - 10 + 'a';
}
int getInt(char ch) {
    if ('0' <= ch && ch <= '9')
        return ch - '0';
    else
        return ch - 'a' + 10;
}
string add(string num1, string num2) {
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    int x, y;
    string res;
    while (i >= 0 || j >= 0 || carry)
    {
        x = i >= 0 ? getInt(num1[i]) : 0;
        y = j >= 0 ? getInt(num2[j]) : 0;
        int temp = x + y + carry;
        res += getChar(temp % 36);
        carry = temp / 36;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

- 高精度减法

```cpp
string sub(string s1, string s2) {
    bool flag = s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2;
    if (flag) swap(s1, s2);
    string ans;
    int t = 0, i = s1.size() - 1, j = s2.size() - 1;
    while (i >= 0) {
        t = s1[i] - '0' - t;
        t -= j >= 0 ? s2[j] - '0' : 0;
        ans += (t + 10) % 10 + '0';
        t = t < 0 ? 1 : 0;
        i--, j--;
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back(); // 删除前导 0
    if (flag) ans += '-'; // 按需添加负号
    reverse(ans.begin(), ans.end());
    return ans;
}
```

- 高精度乘法

```cpp
string mul(string s, int num) {
    string ans;
    int t = 0, i = s.size() - 1;
    while (t || i >= 0) {
        if (i >= 0) t += (s[i] - '0') * num;
        ans += t % 10 + '0';
        t /= 10, i--;
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
```

- 高精度除法

```cpp
pair<string, int> div(string s, int num) {
    pair<string, int> ans = make_pair("", 0);
    for (int i = 0; i < s.size(); i++) {
        ans.second = ans.second * 10 + s[i] - '0';
        ans.first += ans.second / num + '0';
        ans.second %= num;
    }
    while (ans.first.size() > 1 && ans.first.front() == '0')
        ans.first.erase(ans.first.begin());
    return ans;
}
```

## 前缀和/差分

### 前缀和

前缀和数组（矩阵）的第一位（第一行和第一列）为辅助位置，通常为 `0`

- 一维前缀和

```cpp
// stl numeric，pre[0] = a[0]，不含辅助位置
partial_sum(a.begin(), a.end(), pre.begin());
```

```cpp
// pre[0] = 0
vector<int> pre(n + 1);
for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i - 1];
}
```

```cpp
// 计算区间 [l, r] 的区间和
pre[r] - pre[l - 1]
```

- 二维前缀和

```cpp
vector<vector<int>> pre(n + 1, vector<int>(m + 1));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i - 1][j - 1];
    }
}
```

```cpp
// 计算 (x1, y1) 到 (x2, y2) 矩形和
pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]
```

### 差分

差分数组（矩阵）的最后一位（最后一行和最后一列）为辅助位置，在求最终数组（矩阵）时不会被计算到

- 一维差分

```cpp
vector<int> pre(n + 1);
// 向区间 [l, r] 中的所有数加上 c
function<void(int, int, int)> insert = [&] (int l, int r, int c) {
    pre[l] += c, pre[r + 1] -= c;
};
// 求最终数列
vector<int> ans(n);
partial_sum(pre.begin(), pre.end(), ans.begin());
```

- 二维差分

```cpp
vector<vector<int>> pre(n + 1, vector<int>(m + 1));
// 向 (x1, y1) 到 (x2, y2) 区域内的数都加上 c
function<void(int, int, int, int, int)> insert = [&] (int x1, int y1, int x2, int y2, int c) {
    pre[x1][y1] += c, pre[x2 + 1][y1] -= c, pre[x1][y2 + 1] -= c, pre[x2 + 1][y2 + 1] += c;
};
// 计算最终矩阵
vector<vector<int>> ans(n + 1, vector<int>(m + 1));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + pre[i - 1][j - 1];
    }
}
```

## 双指针

首先找到 $O(n^2)$ 的做法

然后寻找 $i$ , $j$ 之间的单调关系，将 $O(n^2)$ 优化为 $O(n)$ 

```cpp
for (int i = 0; i < n; i++) {
	while (check(i, j)) j++;
	// 具体逻辑
}
```

## 位运算

- 二进制表示中第 `k` 位的值

  从最低位 0 开始算起，$k \in [0, log_2x]$ 

```cpp
x >> k & 1;
```

- `lowbit` 

```cpp
x & -x; // 找到 x 二进制表示中最低位 1 的位置，返回的是最低位 1 以及后面的 0 组成的二进制数
```

## 离散化

> 将值域很大但数量较少的一个有序数列映射到从0开始的连续自然数上（通常可以作为数组下标）

```cpp
// 首先将所有需要离散化的值存入 alls
vector<int> alls;
// 对 alls 排序并去重
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());
// 通过二分进行映射
int size = alls.size();
function<int(int)> find = [&] (int x) {
    int l = 0, r = size - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return l + 1; // +1 是映射到从 1 开始的连续自然数上
};
```

## 区间合并

> 将有交集的区间进行合并

```cpp
function<vector<pair<int, int>>(vector<pair<int, int>>&)> merge = [&] (vector<pair<int, int>>& segs) {
    vector<pair<int, int>> ans;
    sort(segs.begin(), segs.end()); // 按照左端点升序进行排序
    pair<int, int> interval = make_pair(INT_MIN, INT_MIN);
    for (auto& seg : segs) {
        if (interval.second < seg.first) { // 没有交集，添加答案
            if (interval.first != INT_MIN) ans.push_back(interval);
            interval = seg;
        }
        else { // 有交集，更新右端点
            interval.second = max(interval.second, seg.second);
        }
    }
    if (interval.first != INT_MIN) ans.push_back(interval); // 判断是否为空
    return ans;
};
```

# 数据结构

## 链表

### 单链表

- 静态链表：数组模拟链表

```cpp
// 一般写法
int head = -1, idx = 0;
vector<int> list, next;
// 在第 k 个插入的数后插入一个数，从 -1 算起，k 为 -1 表示向起始位置插入
function<void(int, int)> add = [&] (int k, int x) {
    if (k == -1) list.push_back(x), next.push_back(head), head = idx++;
    else list.push_back(x), next.push_back(next[k]), next[k] = idx++;
};
// 删除第 k 个插入的数后面的数，从 -1 算起，k 为 -1 表示移除起始位置的数
function<void(int)> remove = [&] (int k) {
    if (k == -1) head = next[head];
    else next[k] = next[next[k]];
};
// 遍历链表
for (int i = head; i != -1; i = next[i]) {
    // list[i];
}
```

```cpp
 // 直接将 head 存进数组下标为 0 的位置，避免特判 head
int idx = 1;
vector<int> list(1, -1), next(1, -1);
// 在第 k 个插入的数后插入一个数，从 0 算起，k 为 0 表示向起始位置插入
function<void(int, int)> add = [&] (int k, int x) {
    list.push_back(x), next.push_back(next[k]), next[k] = idx++;
};
// 删除第 k 个插入的数后面的数，从 0 算起，k 为 0 表示移除起始位置的数
function<void(int)> remove = [&] (int k) {
    next[k] = next[next[k]];
};
for (int i = 0; i != -1; i = next[i]) {
    if(i > 0) // list[i]
}
```

### 双向链表

```cpp
// head 为下标 0 的位置，tail 为下标 1 的位置
int idx = 2;
vector<int> list(2, -1), lptr(2, -1), rptr(2, -);
lptr[1] = 0, rptr[0] = 1;
// 在第 k 个插入的数后插入一个数，k 为 0 表示向 head 后插入，k 为 lptr[1] 表示向 tail 前插入
function<void(int, int)> add = [&] (int k, int x) {
    list.push_back(x);
    lptr.push_back(k), rptr.push_back(rptr[k]);
    lptr[rptr[k]] = idx, rptr[k] = idx++;
};
// 删除第 k 个插入的数后面的数，从 0 算起，k 为 0 表示移除起始位置的数
function<void(int)> remove = [&] (int k) {
    lptr[rptr[k]] = lptr[k], rptr[lptr[k]] = rptr[k];
};
// 遍历链表
for (int i = rptr[0]; i != 1; i = rptr[i]) {
    // list[i];
}
```

## 栈

### 栈

```cpp
int top = 0;
vector<int> stk;
function<void(int)> push = [&] (int x) {
    if (stk.size() <= top) stk.push_back(x), top++;
    else stk[top++] = x;
};
function<void()> pop = [&] () {
    top--;
};
function<bool()> empty = [&] () {
    return top <= 0;
};
function<int()> query = [&] () {
    return stk[top - 1];
};
```

### 单调栈

> 找到一个序列中每个元素左边第一个不大于该元素的元素

性质：对于栈中 $a_i < a_j$ 且 $i < j$ （即 $a_i$ 在 $a_j$ 的底部），那么 $a_i$ 就没有存在的必要

```cpp
stack<int> stk;
vector<int> a(n);
for (int i = 0; i < n; i++) {
    while (!stk.empty() && stk.top() >= a[i]) stk.pop();
    ans[i] = stk.empty() ? -1 : stk.top();
    stk.push(a[i]);
}
```

每个元素最多进栈一次，出栈一次，时间复杂度为 $O(n)$ 

## 队列

### 队列

```cpp
int head = 0, tail = -1;
vector<int> q;
function<void(int)> push = [&] (int x) {
    q.push_back(x), tail++;
};
function<void()> pop = [&] () {
    head++;
};
function<bool()> empty = [&] () {
    return tail - head < 0;
};
function<int()> query = [&] () {
    return q[head];
};
```

### 单调队列

> 求滑动窗口中的最值

```cpp
int n, k; // k 为滑动窗口的长度
vector<int> a(n);
deque<int> q;
for (int i = 0; i < n; i++) {
    if (!q.empty() && q.front() < i - k + 1) q.pop_front(); // 队头超出滑窗范围则删去
    while (!q.empty() && a[q.back()] >= a[i]) q.pop_back(); // >= 为求最小值，若该元素较小，则从队尾删除到队列单调为止
    q.push_back(i);
    // 排除滑窗未满的情况
    if (i >= k - 1) a[q.front()]; // 当前最小值为单调队列的队头
}
```

每个元素最多入队一次，出队一次，时间复杂度为 $O(n)$ 

## 字符串

### 字符串匹配

- KMP字符串匹配

```cpp
string p, s; // p 为 模式串，长度为 n，s 为待匹配字符串，长度为 m
vector<int> next(n); // next[i] 即为 substr(0, i) 的最长公共前后缀的长度
// 计算模式串 p 的 next 数组
for (int i = 1, j = 0; i < n; i++) { // next[0] = 0, 这里直接从 1 开始
    while (j && p[i] != p[j]) j = next[j - 1]; // 若匹配不成功，则 j 向前回溯
    if (p[i] == p[j]) j++; // 匹配成功 j 则向后
    next[i] = j; // 记录当前位置的 next 值
}
// s 和 p 进行匹配
for (int i = 0, j = 0; i < m; i++) {
    while (j && s[i] != p[j]) j = next[j - 1]; // s[i - 1] 和 p[j - 1] 相等，所以 j 回溯到 next[j - 1]，然后再比较 s[i] 和 p[next[j - 1]]，保证了 i 不会回溯
    if (s[i] == p[j]) j++;
    if (j == n) cout << i - j + 1 << " "; // 匹配成功，模式串 p 在 字符串 s 中出现的起始下标位置
}
```

## 字典树 `Trie` 

> 存储和查找字符串集合

```cpp
const int maxn = 26; // 出现的字符种类数，以 26 个小写英文字母为例
// 字典树，用一个 vector 存储所有节点，节点为一个 pair，first 为该节点之后下一位置的下标，无效为 0；second 为以该节点结尾的字符串的个数
vector<pair<vector<int>, int>> trie(1, make_pair(vector<int>(maxn), 0));
// 向字典树中添加一个字符串 s
function<void(string)> insert = [&] (string s) {
    int pos = 0;
    for (auto& e : s) {
        if (trie[pos].first[e - 'a'] == 0) { // 不存在则添加
            trie[pos].first[e - 'a'] = trie.size();
            trie.push_back(make_pair(vector<int>(maxn), 0));
        }
        pos = trie[pos].first[e - 'a'];
    }
    trie[pos].second++; // 记录结尾
};
// 查找字典树中字符串 s 出现的次数
function<int(string)> query = [&] (string s) {
    int pos = 0;
    for (auto& e : s) {
        if (trie[pos].first[e - 'a'] == 0) return 0;
        pos = trie[pos].first[e - 'a'];
    }
    return trie[pos].second;
};
```

## 并查集

> 维护一些集合的集合，可以将其中的两个集合合并，可以快速判断两个元素是否属于同一个集合

### 基本操作

```cpp
vector<int> disjoint_set;
// 查找 x 的父节点，同时进行路径压缩
function<int(int)> find = [&] (int x) {
    if (disjoint_set[x] != x) disjoint_set[x] = find(disjoint_set[x]);
    return disjoint_set[x];
};
// 将 a, b 元素所在的两个集合合并
function<void(int, int)> set_union = [&] (int a, int b) {
    disjoint_set[find(a)] = find(b); // 即将 b 所在树的根节点加到 a 所在树根节点的下面
};
// 查询 a, b 元素是否在同一个集合中
function<bool(int, int)> query = [&] (int a, int b) {
    return find(a) == find(b);
};
```

### 维护额外信息

- 集合元素个数

```cpp
vector<pair<int, int>> disjoint_set; // pair 中的 first 为当前节点的父节点下标，second 为当前节点为根时集合中的元素个数，当且仅当 disjoint_set[x] = x 即当前节点为根节点时 second 值才有意义
// 查找 x 的父节点，同时进行路径压缩
function<int(int)> find = [&] (int x) {
    if (disjoint_set[x].first != x) disjoint_set[x].first = find(disjoint_set[x].first);
    return disjoint_set[x].first;
};
// 查询 a, b 元素是否在同一个集合中
function<bool(int, int)> together = [&] (int a, int b) {
    return find(a) == find(b);
};
// 将 a, b 元素所在的两个集合合并
function<void(int, int)> set_union = [&] (int a, int b) {
    if (together(a, b)) return;
    disjoint_set[find(b)].second += disjoint_set[find(a)].second;
    disjoint_set[find(a)].first = find(b);
};
// 返回元素 a 所在集合的元素个数
function<int(int)> set_size = [&] (int a) {
    return disjoint_set[find(a)].second;
};
```

- 当前节点到根节点的距离

```cpp
vector<pair<int, int>> disjoint_set; // pair 中的 first 为当前节点的父节点下标，second 为当前节点到根节点的距离
// 若并不是只有根节点有意义的数据，find 需要返回整个 pair
function<pair<int, int>(int)> find = [&] (int x) {
    if (disjoint_set[x].first != x) {
        pair<int, int> t = find(disjoint_set[x].first); // 先保存当前节点的根节点
        disjoint_set[x].second += disjoint_set[disjoint_set[x].first].second; // 更新距离
        disjoint_set[x].first = t.first; // 将当前节点接到根节点，完成路径压缩
    }
    return disjoint_set[x];
};
```

## 堆

> 维护一个数据集合，能够快速得到该集合的最值

- 一般的堆，无法对堆中的某个特定数进行操作

```cpp
int size = 0;
// 下标从 1 开始存储完全二叉树，2x 为 x 的左儿子，2x + 1 为 x 的右儿子，x / 2 为 x 的父节点
vector<int> heap(size + 1);
// 向上调整，与父节点比较
function<void(int)> up = [&] (int x) {
    while (x / 2 != 0 && heap[x / 2] > heap[x]) {
        swap(heap[x], heap[x / 2]);
        x /= 2;
    }
};
// 向下调整，与左右儿子比较，找到三个节点中的最小
function<void(int)> down = [&] (int x) {
    int t = x;
    if (x * 2 <= size & heap[x * 2] < heap[t]) t = x * 2;
    if (x * 2 + 1 <= size & heap[x * 2 + 1] < heap[t]) t = x * 2 + 1;
    if (t != x) swap(heap[x], heap[t]), down(t);
};
// 插入节点，将节点插入到尾部，再向上调整
function<void(int)> insert = [&] (int x) {
    size++;
    if (heap.size() > size) heap[size] = x;
    else heap.push_back(x);
    up(size);
};
// 删除节点，将节点移到最后，进行删除并调整
function<void(int)> remove = [&] (int x) {
    swap(heap[x], heap[size--]);
    up(x), down(x);
};
// 初始化堆，从 size / 2 处开始向下调整即可（叶子节点无需向下调整），初始化的复杂度为 O(n)
for (int i = size / 2; i >= 0; i--) down(i);
```

- 需要对堆中某个数进行操作，从而需要维护下标间映射关系

```cpp
int size = 0, idx = 0; // idx 为已经插入点的数量
// 映射关系：ph[k] 第 k 个插入点在堆中的下标，hp[k] 堆中下标为 k 数的插入次序（ph 数组中的下标）
vector<int> heap(maxn), ph(maxn), hp(maxn);
// 交换的同时需要更新映射关系
function<void(int, int)> heap_swap = [&] (int x, int y) {
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(heap[x], heap[y]);
};
function<void(int)> up = [&] (int x) {
    while (x / 2 != 0 && heap[x] < heap[x / 2]) {
        heap_swap(x, x / 2);
        x /= 2;
    }
};
function<void(int)> down = [&] (int x) {
    int t = x;
    if (x * 2 <= size && heap[x * 2] < heap[t]) t = x * 2;
    if (x * 2 + 1 <= size && heap[x * 2 + 1] < heap[t]) t = x * 2 + 1;
    if (x != t) heap_swap(x, t), down(t);
};
// 向堆中插入一个数，插入到堆的最后，更新映射关系后再向上调整
function<void(int)> insert = [&] (int x) {
    idx++, size++;
    ph[idx] = size; hp[size] = idx;
    heap[size] = x;
    up(size);
};
function<void(int)> remove = [&] (int x) {
    heap_swap(x, size--);
    up(x), down(x);
};
// 修改下标为 k 的节点值为 x
function<void(int, int)> modify = [&] (int k, int x) {
    heap[k] = x;
    up(k), down(k);
};
```

## 哈希表

### 一般哈希

- 链式寻址法

```cpp
const int mod = 100003; // 质数且距离 2 的整次幂较远时冲突概率较小
int idx = 0;
vector<int> hash_list, list, next;
// idx list next 为单链表相关，用这样一个单链表模拟多个邻接的链表，即 next 数组中有多少个 -1，就有多少个邻接的链表，hash_list[i] 为头节点
// 哈希函数
function<int(int)> hash = [&] (int x) {
    return (x % mod + mod) % mod;
};
// 向哈希表中添加元素 x
function<void(int)> insert = [&] (int x) {
    int code = hash(x);
    list.push_back(x), next.push_back(hash_list[code]);
    hash_list[code] = idx++;
};
// 查询 x 是否再哈希表中
function<bool(int)> query = [&] (int x) {
    int code = hash(x);
    for (int i = hash_list[code]; i != -1; i = next[i]) {
        if (list[i] == x) return true;
    }
    return false;
};
```

- 开放寻址法

```cpp
// 开放寻址法哈希表的长度通常要开到数据量的两到三倍，降低冲突概率
// 0x3f3f3f3f 的十进制为 1061109567，1e9 数量级
const int mod = 200003, mark = 0x3f3f3f3f;
vector<int> hash_list(mod, mark);
function<int(int)> hash = [&] (int x) {
    return (x % mod + mod) % mod;
};
// 开放寻址法的核心，若 x 存在返回 x 的位置，不存在则返回 x 应该插入的位置
function<int(int)> find = [&] (int x) {
    int code = hash(x);
    while (hash_list[code] != mark && hash_list[code] != x) {
        code++;
        if (code == mod) code = 0;
    }
    return code;
};
function<void(int)> insert = [&] (int x) {
    int pos = find(x);
    hash_list[pos] = x;
};
function<bool(int)> query = [&] (int x) {
    int pos = find(x);
    return hash_list[pos] != mark;
};
```

### 字符串哈希

> 字符串前缀哈希法
>
> 可以快速判断两个字符串的子串是否相同

#### 哈希原理

将字符串看作一个 `p` 进制的数，可以通过如下公式将任意一个字符串映射成一个 `0` 到 `q - 1` 的值
$$
hash("ABCD") = hash(1234)_p = (1 \times p^3 + 2 \times p^2 + 3 \times p^1 + 4 \times p^0) \bmod q
$$
通常情况下取经验值：
$$
p = 131 或 13331 \\
q = 2^{64}
$$

#### 求任意字串的哈希值

预处理字符串 `s` 的每一个前缀的哈希值
$$
hash(0, i) = hash(0, i - 1) \times p + s[i]
$$
已知 `hash(0, l)` 和 `hash(0, r)` 的情况下求 `hash(l, r)` 
$$
hash(l, r) = (hash(0, r) - hash(0, l) \times p^{r - l + 1}) \bmod q
$$

```cpp
const ull p = 131;
int n;
string s;
cin >> n >> s;
vector<ull> hash(n + 1), base(n + 1, 1);
// 预处理 p 的幂以及 s 的前缀哈希值
for (int i = 1; i <= n; i++) {
    base[i] = base[i - 1] * p;
    hash[i] = hash[i - 1] * p + s[i - 1];
}
// 查询某个字串的哈希值（数组下标从 0 开始）
function<ull(int, int)> query = [&] (int l, int r) {
    return hash[r + 1] - hash[l] * base[r - l + 1];
};
```

# 数学

## 质数

### 质数判断

```cpp
function<bool(int)> check_prime = [&] (int num) {
  	if (n < 2) return false;
		for (int i = 2; i <= n / i; i++)
  			if (n % i == 0) return false;
		return true;
};
```

### 分解质因数

```cpp
function<vector<pair<int, int>>(int)> get_prime_fact = [&] (int n) {
  	// pair<int, int> 为质因数的底数和指数
    vector<pair<int, int>> res;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            res.push_back({i, s});
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
};
```

### 质数筛

- 埃氏筛

埃拉托色尼素数筛选法是找出在$[1, n]$范围内所有素数的方法，时间复杂度 $O(nloglogn)$ 

```cpp
function<vector<bool>(int)> get_prime = [&] (int maxn) {
    vector<bool> is_prime(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxn / i; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
};
```

- 线性筛

```cpp
function<vector<bool>(int)> get_prime = [&] (int maxn) {
    vector<int> primes;
    vector<bool> is_prime(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxn; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= maxn / i; j++) {
            is_prime[primes[j] * i] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return is_prime;
};
```

## 因数

### 所有因数

```cpp
function<vector<int>(int)> get_fact = [&] (int num) {
    vector<int> res;
    for (int i = 1; i <= num / i; i++) {
        if (num % i == 0) {
            res.push_back(i);
            if (i != num / i) res.push_back(num / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
};
```

### 因数个数



## 最大公因数/最小公倍数

```cpp
// gcd & lcm
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

## 线性基

- 线性基是一个集合，从原集合中选取任意多个数进行异或得到的值都能通过在线性基中选取一些数进行异或得到，可以将线性基理解为对原集合的一个压缩。

## 裴蜀定理

对于不全为 $0$ 的任意整数 $a, b$ ，记 $g = gcd(a, b)$ ，则对于任意整数 $x, y$ 都满足 $a \times x + b \times y$ 是 $g$ 的倍数。

## 牛顿法求平方根

```cpp
function<double(double)> sqrt = [&] (double x) {
	double z = 1.0;
	for (int i = 0; i < 10; i++) {
		z -= (z * z - x) / (2 * z)
	}
	return z;
}

```

# 搜索与图论

## 深度优先搜索

- 回溯

  在向上回溯的过程中一定要恢复现场，保证分支上的同一节点的状态相同

```
func dfs(status) {
		status = new;
		dfs(status);
		status = old;
}
```

- 剪枝

## 广度优先搜索

```
queue<status> q;
while (!empty()) {
  	status cnt = q.front();
  	q.pop();
  	q.push(from status get other status)
}
```

## 最短路

### Dijkstra堆优化

```cpp
// edge中第i个vector<pair<int, int>>存了第i个点出发的所有边，pair<int, int>中第一个int是终点，第二个int是边权
inline int dijsktra(vector<vector<pair<int, int>>> edge, int s, int t) {
    vector<int> dist(n + 1, (1 << 30) + 1);
    dist[s] = 0;
    // pair<int, int>的小根堆，第一个int代表边权，第二个int代表点的编号
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
        int x = q.top().second;
        if (x == t || dist[x] > 1 << 30) {
            break;
        }
        q.pop();
        for (auto it : edge[x]) {
            if (dist[x] + it.second < dist[it.first]) {
                dist[it.first] = dist[x] + it.second;
                q.push(make_pair(dist[it.first], it.first));
            }
        }
    }
    if (dist[t] > 1 << 30) {
        return -1;
    }
    return dist[t];
}
```

# 动态规划

## 动态规划问题的分析方法

### 状态表示

> 分析状态表示需要的维度

- 集合
  - 每个状态表示的是哪一个集合
  - 每一个状态都用一个集合来表示
- 属性
  - 需要考虑维护该集合的哪个属性，如：最大值、最小值、元素数量等

### 状态计算

> 分析一个状态可以由哪些状态如何得到

- 集合的划分
  - 考虑如何将一个集合表示的状态 **划分** 成更小的若干个，并分析更小的状态如何转换到该状态
  - 划分原则
    - 不重复
    - 不遗漏 

### 优化

> 对转移方程做等价变形

## 背包问题

### 01 背包问题

- 问题描述：

  有 `N` 件物品和一个容量是 `V` 的背包。每件物品只能使用一次。

  第 `i` 件物品的体积是 `vi`，价值是 `wi`。

  求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

- 特点：每件物品只有一个

- 朴素写法

  ```cpp
  vector<vector<int>> dp(n + 1, vector<int>(maxv + 1));
  for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= maxv; j++) {
          if (j < v[i - 1]) dp[i][j] = dp[i - 1][j];
          else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
      }
  }
  ```

- 滚动数组优化

  ```cpp
  vector<int> dp(m + 1);
  for (int i = 0; i < n; i++) {
      for (int j = m; j >= v[i]; j--) {
          dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
      }
  }
  ```

### 完全背包问题

- 特点：每件物品有无限个

- 问题描述：

  有 `N` 件物品和一个容量是 `V` 的背包。每件物品有无限个。

  第 `i` 件物品的体积是 `vi`，价值是 `wi`。

  求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

- 朴素写法

  ```cpp
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
          for (int k = 0; k * v[i - 1] <= j; k++) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i - 1]] + k * w[i - 1]);
          }
      }
  }
  ```

- 对枚举每件物品的个数进行优化
  
  ```cpp
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
          dp[i][j] = dp[i - 1][j];
          if (j >= v[i - 1]) dp[i][j] = max(dp[i][j], dp[i][j - v[i - 1]] + w[i - 1]);
      }
  }
  ```

- 滚动数组优化

  ```cpp
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; i++) {
      for (int j = v[i - 1]; j <= m; j++) {
          dp[j] = max(dp[j], dp[j - v[i - 1]] + w[i - 1]);
      }
  }
  ```

### 多重背包问题

- 特点：每件物品有个数限制

- 问题描述：

  有 `N` 种物品和一个容量是 `V` 的背包。

  第 `i` 种物品最多有 `si` 件，每件体积是 `vi`，价值是 `wi` 。

  求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。

- 朴素写法

  ```cpp
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
          for (int k = 0; k <= s[i - 1] && k * v[i - 1] <= j; k++) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i - 1]] + k * w[i - 1]);
          }
      }
  }
  ```

  - 有一个问题困扰我很久了，`max` 函数第一个参数为什么是 `dp[i][j]` 而不是 `dp[i - 1][j]` 

    因为完全背包和多重背包在不取第 `i` 个物品的时候，都是从本层转移得到的，朴素算法下对于每一个 `dp[i][j]` 都要计算 `k` 次

- 二进制倍增优化

  - 将多重背包通过二进制倍增转换为 01 背包
  - 即将每一组物品捆绑成 `1, 2, 4, 8, 16···` 这样的小份，将每一小份看作是 01 背包中的每一件物品，这样既能保证将每一组物品中选多少个都覆盖到，同时优化了时间复杂度

  ```cpp
  for (int i = 0; i < n; i++) {
      int x, y, s;
      cin >> x >> y >> s;
      int k = 1;
      while (k <= s) {
          v.push_back(k * x);
          w.push_back(k * y);
          s -= k, k *= 2;
      }
      if (s > 0) {
          v.push_back(s * x);
          w.push_back(s * y);
      }
  }
  n = v.size();
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; i++) {
      for (int j = m; j >= v[i - 1]; j--) {
          dp[j] = max(dp[j], dp[j - v[i - 1]] + w[i - 1]);
      }
  }
  ```

### 分组背包问题

- 特点：物品被分组，每组之内只能选一种物品

- 题目描述：

  有 `N` 组物品和一个容量是 `V` 的背包。

  每组物品有若干个，同一组内的物品最多只能选一个。
  每件物品的体积是 `v[i, j]`，价值是 `w[i, j]`，其中 `i` 是组号，`j` 是组内编号。

  求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。输出最大价值。

- 与多重背包思路相似

  - 多重背包：考虑该组物品取多少个
  - 分组背包：考虑该组物品取哪一个

- 优化为一维写法的注意点：

  - 状态由本层转移：从前到后枚举
  - 状态由上一层转移：从后到前枚举

- ```cpp
  vector<int> dp(m + 1);
  for (int i = 0; i < n; i++) {
      for (int j = m; j >= 0; j--) {
          int size = v[i].size();
          for (int k = 0; k < size; k++) {
              if (j - v[i][k] >= 0) dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
          }
      }
  }
  ```

## 线性 DP

# 经典问题

### 求数组的逆序对数量

> 归并排序

```cpp
function<int(int, int)> merge_sort = [&] (int l, int r) {
    if (l == r) return 0;
    int mid = l + r >> 1;
    int ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp.push_back(a[i++]);
        }
        else {
            tmp.push_back(a[j++]);
            ans += mid - i + 1;
        }
    }
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
    return ans;
};
```

### 使数组有序的最小交换次数

```cpp
int getMinSwaps(vector<int>& arr) {
    int size = arr.size();
    vector<pair<int, int>> res(size);
    for (int i = 0; i < size; i++) {
        res[i].first = arr[i];
        res[i].second = i;
    }
    sort(res.begin(), res.end());
    int ans = 0;
    vector<bool> vis(size, false);
    for (int i = 0; i < size; i++) {
        if (vis[i] || res[i].second == i) continue;
        int idx = i, tmp = 0;
        while (!vis[idx]) {
            vis[idx] = true;
            tmp++;
            idx = res[idx].second;
        }
        ans += (tmp - 1);
    }
    return ans;
}
```

### 字符串分割

```cpp
vector<string> split(const string & str, char target) {
    vector<string> res;
    string s(str);
    int pos = 0;
    while (pos < s.size()) {
        while (pos < s.size() && s[pos] == target) pos++;
        int start = pos;
        while (pos < s.size() && s[pos] != target) pos++;
        if (pos > start) res.emplace_back(s.substr(start, pos - start));
    }
    return res;
}
```

