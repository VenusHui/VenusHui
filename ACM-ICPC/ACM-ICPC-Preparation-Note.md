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

## 数学

```cpp
// gcd & lcm
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

## 高精度

### 加法

- 高精度加法

```cpp
// 高精度加法板子
string add(string num1, string num2)
{
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || carry)
    {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int temp = x + y + carry;
        res += '0' + temp % 10;
        carry = temp / 10;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

- 小于等于 `n` 进制高精度加法

```cpp
// 小于等于36进制高精度加法板子
char getChar(int n)
{
    if (n <= 9)
        return n + '0';
    else
        return n - 10 + 'a';
}
int getInt(char ch)
{
    if ('0' <= ch && ch <= '9')
        return ch - '0';
    else
        return ch - 'a' + 10;
}
string add(string num1, string num2)
{
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

# 数论

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