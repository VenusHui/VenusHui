> writer: VenusHui
>  
> time: 2021.09.15
>
> last edit: 2021.09.15
>  
> Reference: [ACM-ICPC-Preperation On Github](https://github.com/BedirT/ACM-ICPC-Preparation)

# ACM-ICPC-Preperation

## Week 01

### 高精度

#### 加法

```cpp
// 高精度加法板子
string add(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int n = max(n1, n2);
    string res(n + 1, '0');
    for (int i = n1; i < n; i++) {
        s1.insert(0, "0");
    }
    for (int i = n2; i < n; i++) {
        s2.insert(0, "0");
    }
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = 0;
        if (s1[i])
            x += s1[i] - '0';
        else
            x += 0;
        if (s2[i])
            x += s2[i] - '0';
        else
            x += 0;
        x += r;
        if (x >= 10) {
            x -= 10;
            r = 1;
        }
        else
            r = 0;
        res[i + 1] = x + '0';
    }
    res[0] = r + '0';
    for (int i = 0; i <= n; i++) {
        if (res[i] != '0')
            return res.substr(i);
    }
    return "0";
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


