> writer: VenusHui
>  
> time: 2021.09.15
>
> last edit: 2021.09.15
>  
> Reference: [ACM-ICPC-Preperation On Github](https://github.com/BedirT/ACM-ICPC-Preparation)

# ACM-ICPC-Preperation

## Week 01

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
