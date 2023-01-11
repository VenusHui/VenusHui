> writer: VenusHui
>  
> time: 2021.09.15
>
> last edit: 2023.01.09
>  
> Reference: 

# 基本算法

## 排序

### 快速排序

```cpp
void quick_sort(vector<int>& a, int l, int r) {
    if (l == r) {
        return;
    }
    int x = a[l + r >> 1]; // 选取partition的方式
    int i = l - 1, j = r + 1;
    while (i < j) {
        do {
            i++;
        } while (a[i] < x); // 注意这里是小于而不是小于等于
        do {
            j--;
        } while (a[j] > x);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
    return;
}
```

### 归并排序

```cpp
void merge_sort(vector<int>& a, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp.push_back(a[i++]);
        }
        else {
            tmp.push_back(a[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(a[i++]);
    }
    while (j <= r) {
        tmp.push_back(a[j++]);
    }
    for (i = l, j = 0; i <= r; i++, j++) { // i 循环原始数组，j 循环 tmp 数组
        a[i] = tmp[j];
    }
    return;
}
```

## 二分

```cpp
int l = 0, r = n - 1;
while (l < r) {
    int m = l + r >> 1; // 是否 +1 与区间的更新方式有关
    if (check(m)) {
        l = mid + 1;
    }
    else {
        r = mid;
    }
}
return l;
```

```cpp
int l = 0, r = n - 1;
while (l < r) {
	int m = l + r + 1 >> 1; // 是否 +1 与区间的更新方式有关
	if (check(m)) {
		l = mid;
	}
	else {
		r = mid - 1;
	}
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

# 数论

## 最大公因数/最小公倍数

```cpp
// gcd & lcm
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

## 质数筛

### 埃拉托色尼筛法

> Sieve of Eratosthenes

* 埃拉托色尼素数筛选法是找出在$[1, n]$范围内所有素数的方法，时间复杂度 $O(nloglogn)$

```cpp
int n;
cin >> n;
vector<bool> prime(n + 1, true);
prime[0] = prime[1] = false;
for (int i = 2; pow(i, 2) < n; i++) {
    if (prime[i]) {
        for (int j = pow(i, 2); j <= n; j += i) {
            prime[j] = false;
        }
    }
}
```
## 线性基

- 线性基是一个集合，从原集合中选取任意多个数进行异或得到的值都能通过在线性基中选取一些数进行异或得到，可以将线性基理解为对原集合的一个压缩。

# 图论

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

# 经典问题

- 求数组的逆序对数量（归并排序）

```cpp
function<int(int, int)> merge_sort = [&] (int l, int r) {
    if (l == r) {
        return 0;
    }
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
    while (i <= mid) {
        tmp.push_back(a[i++]);
    }
    while (j <= r) {
        tmp.push_back(a[j++]);
    }
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = tmp[j];
    }
    return ans;
};
```

- 使数组有序的最小交换次数

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
        if (vis[i] || res[i].second == i) {
            continue;
        }
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