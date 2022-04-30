> writer: VenusHui
>  
> time: 2021.09.15
>
> last edit: 2021.09.15
>  
> Reference: 

### 高精度

#### 加法

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

### 埃拉托色尼筛法(Sieve of Eratosthenes)

* 埃拉托色尼素数筛选法是找出在$[1, n]$范围内所有素数的方法，时间复杂度$O(nloglogn)$

* 算法思想：

* 代码实现：

```cpp
int n;
cin >> n;
vector<bool> prime(n + 1, true);
prime[0] = prime[1] = false;
for (int i = 2; pow(i, 2) < n; i++)
{
    if (prime[i])
    {
        for (int j = pow(i, 2); j <= n; j += i)
        {
            prime[j] = false;
        }
    }
}
```
### 线性基

- 线性基是一个集合，从原集合中选取任意多个数进行异或得到的值都能通过在线性基中选取一些数进行异或得到，可以将线性基理解为对原集合的一个压缩。


## 图论

### 最短路

#### Dijkstra堆优化

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