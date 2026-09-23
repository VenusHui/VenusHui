---
title: Leetcode第286场周赛题解
date: 2022-03-31
tags: [leetcode, contest-solution]
series: contest-solution
summary: 比赛时间：2022/3/27 10:30-12:00，排名：3395/7248
lang: zh
---

![](https://fc.dianhsu.top/lc?user=VenusHui&loc=cn&req=rating)

## [Leetcode第286场周赛](https://leetcode.cn/contest/weekly-contest-286/)

### [第一题 找出两数组的不同](https://leetcode.cn/problems/find-the-difference-of-two-arrays/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

由于是求不同整数所组成的列表，所以可以先用两个 `set` 对 `nums1` 和 `nums2` 进行去重，且由于 `set` 的特性，我们会得到两个排好序的集合。

```cpp
set<int> s1;
set<int> s2;
for (int i = 0; i < size1; i++) {
    s1.insert(nums1[i]);
}
for (int i = 0; i < size2; i++) {
    s2.insert(nums2[i]);
}
```

由于 `set` 的有序性，去重之后只需要分别遍历两个 `set` ，将未在另一个集合中出现的元素加入到答案列表中即可。

```cpp
vector<int> tmp;
set<int>::iterator it;
for (it = s1.begin(); it != s1.end(); it++) {
    if (s2.find(*it) == s2.end()) {
        tmp.push_back(*it);
    }
}
ans.push_back(tmp);
```

#### 复杂度分析

- 时间复杂度：外层只是对数组进行了遍历操作，时间复杂度为*O(n)*；去重操作利用到了 `set` ，插入和查询的时间复杂度均为 _O(logn)_ ；综上，总的时间复杂度为 _O(nlogn)_ 。

- 空间复杂度：利用到了两个集合存储去重后的数组，；两个列表存储答案，总的空间复杂度为 _O(n)_ 。

### [第二题 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

按照题目的描述，我们需要删除所有下标为偶数，且该位置与其后继位置元素相等的元素，所以可以使用**模拟+贪心**的思想：

即维护一个变量 `ans` 表示当前已经删除元素的个数，则当前元素在数组中的下标即为原始下标减去 `ans` ，之后遍历整个数组，当遍历到当前下标为偶数且元素值与后继相同时，更新 `ans` 的值。

```cpp
int ans = 0;
for (int i = 1; i < size; i++) {
    if ((i - 1 - ans) % 2 == 0 && nums[i] == nums[i - 1]) {
        ans++;
    }
}
```

最后注意 **美丽数组 **的第一个条件，若此时数组元素为奇数个，则需要再删除一个元素。

#### 复杂度分析

- 时间复杂度：只对数组进行了遍历操作，时间复杂度为 _O(n)_ 。

- 空间复杂度：只用了一个变量来记录已经删除的元素个数，空间复杂度为 _O(1)_ 。

### [第三题 找到指定长度的回文数](https://leetcode.cn/problems/find-palindrome-with-fixed-length/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

首先由于回文数的特性，我们只需要考虑前`len = (intLength + 1) / 2`位数即可，后半部分为前半部分倒置。所以使用一个长度为`intLength`的数组来记录所求回文数的每一位，在计算的时候使用两个指针 `l` , `r` 指向数组的头尾并且向着中间逼近：

```cpp
vector<int> nums(length + 1);
for (int l = 1, r = length; l < len; l++, r--) {
    int tmp;
    // 计算第l位上tmp的值
    nums[l] = nums[r] = tmp;
}
```

按照题意，最小的回文数从`100···001`开始算起，则考虑时应将每个询问都先减去 `1` 。前`len`位数为`100···`第一位从 `1` 算起，其余位均从 `0` 算起，所以对于任意一个询问 `q - 1` ，第 `q` 小回文数的第一位应该为 `(q - 1) / pow(10, len - 1) + 1`，之后的第 `i` 位应该为 `(q - 1) / pow(10, len - 1)`。

```cpp
vector<int> nums(length + 1);
for (int l = 1, r = length; l <= len; l++, r--) {
    int tmp;
    if (l == 1) {
        tmp = q / index[len - l] + 1;
    }
    else {
        tmp = q / index[len - l];
    }
    nums[l] = nums[r] = tmp;
    q %= index[len - l];
}
```

考虑到 `pow()`的速度很慢且这里需要多次用到幂来计算每个数位上的值，我们可以对10的 `intLength` 次幂进行一个预处理：

```cpp
vector<long long> index(length + 1);
index[0] = 1;
for (int i = 1; i <= length; i++) {
    index[i] = index[i - 1] * 10;
}
```

#### 复杂度分析

- 时间复杂度：由于本题回文数最多为 `15` 位，所以每次求回文数的复杂度为 _O(1)_ ，共有 _n_ 次查询，总的时间复杂度为 _O(n)_。

- 空间复杂度：本题使用了长度为 `intLength` 的两个数组用于预处理幂的值以及存储回文数每一位的值，复杂度为 _O(1)_ ，共有 _n_ 次查询，总的空间复杂度为 _O(n)_。

### [第四题 从栈中取出 K 个硬币的最大面值和](https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

本题是一道非常经典的背包问题:

状态：用 `dp[i][j]` 表示考虑了前 `i` 个栈，共取出了 `j` 个硬币能获得的最大面值之和。

由于栈的特性，要取得栈中的第 `x` 个元素就必须取得前 `x - 1` 个元素，所以维护一个变量 `cnt` 来记录栈中前 `x` 个元素的和（**前缀和**）

则转移方程为：

```text
dp[i][j] = max(dp[i][j], dp[i - 1][j], dp[i - 1][j - x] + cnt)
```

其中 `x` 表示在第 `i` 个栈取到的硬币个数，`cnt` 表示第 `i` 个栈前 `x` 个硬币的面值之和。

```cpp
for (int i = 1; i <= size; i++) {
    int n = p[i - 1].size();
    for (int j = 1; j <= k; j++) {
        int cnt = 0;
        for (int x = 1; x <= n && x <= j; x++) {
            cnt += p[i - 1][x - 1];
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + cnt);
        }
    }
}
```

#### 复杂度分析

二维背包的时间和空间复杂度均为 `O(nm)` 。

## 完整AC代码

```cpp
// 第一题 找出两数组的不同
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        int size1 = nums1.size(), size2 = nums2.size();
        set<int> s1;
        set<int> s2;
        for (int i = 0; i < size1; i++) {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < size2; i++) {
            s2.insert(nums2[i]);
        }
        vector<int> tmp;
        set<int>::iterator it;
        for (it = s1.begin(); it != s1.end(); it++) {
            if (s2.find(*it) == s2.end()) {
                tmp.push_back(*it);
            }
        }
        ans.push_back(tmp);
        tmp.clear();
        for (it = s2.begin(); it != s2.end(); it++) {
            if (s1.find(*it) == s1.end()) {
                tmp.push_back(*it);
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};

// 第二题 美化数组的最少删除数
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for (int i = 1; i < size; i++) {
            if ((i - 1 - ans) % 2 == 0 && nums[i] == nums[i - 1]) {
                ans++;
            }
        }
        if ((size - ans) % 2 != 0) {
            ans++;
        }
        return ans;
    }
};

// 第三题 找到指定长度的回文数
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& qr, int length) {
        bool odd = length % 2;
        int len = (length + 1) / 2;
        vector<long long> index(length + 1);
        index[0] = 1;
        for (int i = 1; i <= length; i++) {
            index[i] = index[i - 1] * 10;
        }
        vector<long long> ans;
        int size = qr.size();
        for (int i = 0; i < size; i++) {
            int q = qr[i] - 1;
            bool flag = true;
            vector<int> nums(length + 1);
            for (int l = 1, r = length; l <= len && flag; l++, r--) {
                int tmp;
                if (l == 1) {
                    tmp = q / index[len - l] + 1;
                }
                else {
                    tmp = q / index[len - l];
                }
                if (tmp > 9) {
                    flag = false;
                    break;
                }
                nums[l] = nums[r] = tmp;
                q %= index[len - l];
            }
            if (!flag) {
                ans.push_back(-1);
            }
            else {
                long long num = 0;
                for (int j = 1; j <= length; j++) {
                    num  = num * 10 + nums[j];
                }
                ans.push_back(num);
            }
        }
        return ans;
    }
};

// 第四题 从栈中取出 K 个硬币的最大面值和
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        int size = p.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1));
        for (int i = 1; i <= size; i++) {
            int n = p[i - 1].size();
            for (int j = 1; j <= k; j++) {
                int cnt = 0;
                for (int x = 1; x <= n && x <= j; x++) {
                    cnt += p[i - 1][x - 1];
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + cnt);
                }
            }
        }
        return dp[size][k];
    }
};
```
