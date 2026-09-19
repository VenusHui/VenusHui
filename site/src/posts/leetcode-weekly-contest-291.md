---
title: Leetcode第291场周赛题解
date: 2022-05-02
tags: [leetcode, contest-solution]
summary: 比赛时间：2022/05/01 10:30-12:00，排名：1933/6514
lang: zh
---

![](https://fc.dianhsu.top/lc?user=VenusHui&loc=cn&req=rating)

> 好久不见了啊大家，现在是凌晨的1:28分，让我们来赶紧写一下今天（科学的讲应该是昨天）的周赛题解吧~

## [Leetcode第291场周赛](https://leetcode.cn/contest/weekly-contest-291/)

### [第一题 移除指定数字得到的最大结果](https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

第一题就是很常规的暴力模拟啦，我们直接遍历给的字符串，遇到 `digit` 就将这个字符删去，然后将剩余的串作为备选答案，最后在所有备选答案中找到一个最大的就可以下一题了~

由于十进制最大就是字典序最大，所以这里可以通过两个string进行 `max()` 省去存储较小备选答案的空间。

```cpp
if (number[i] == digit) {
    string tmp = number;
    tmp.erase(tmp.begin() + i);
    ans = max(tmp, ans);
}
```

#### 复杂度分析

- 时间复杂度：由于遍历了整个字符串，以字符串的位数为 _n_ 的话，时间复杂度为 _O(n)_。

- 空间复杂度：只需要一个字符串存储最终答案，以字符串的位数为 _n_ 的话，空间复杂度为 _O(n)_。

其实处理一个字符串的问题我觉得时间和空间复杂度说是 _O(1)_ 也对吧？

### [第二题 必须拿起的最小连续卡牌数](https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

从贪心的角度，要使拿起的连续卡牌数最小，那么拿起这一串卡牌的开头和结尾的卡牌应该是匹配的。

所以我们只需要找到所有能够匹配的卡牌所出现的位置，这里可以使用 `map<int, vector<int>>` ，其中第一关键字为卡牌的值，第二关键字为该值出现的位置序列。

```cpp
map<int, vector<int>> mp;
for (int i = 0; i < size; i++) {
    if (mp.find(cards[i]) == mp.end()) {
        vector<int> tmp(1, i);
        mp.insert(make_pair(cards[i], tmp));
    }
    else {
        mp.find(cards[i])->second.push_back(i);
    }
}
```

然后找到其中间距最小的即可:

```cpp
for (auto &it : mp) {
    int vsize = it.second.size();
    for (int i = 0; i < vsize - 1; i++) {
        ans = min(ans, it.second[i + 1] - it.second[i] + 1);
    }
}
```

#### 复杂度分析

- 时间复杂度：对于整个卡牌序列遍历的复杂度是 _O(n)_，每次在map中进行查找或插入的复杂度是 _O(logn)_，则预处理map的复杂度是 _O(nlogn)_。最后遍历整个map，由于刚好每个元素都遍历了一遍，所以复杂度（应该）也是 _O(n)_，尽管这里出现了两个for语句的嵌套。

  值得一提的是，想起来之前wls双周赛因为 `auto` 和 `auto&` TLE的故事，我这里也试了这两者之间的区别，实测 `auto&` 能比 `auto` 快200ms左右，性能提升约为25%（仅针对这一题在LeetCode的测试数据而言），所以能用 `auto&` 还是别用 `auto` 了

- 空间复杂度：这里用map的空间复杂度应为 _O(nlogn)_

### [第三题 含最多 K 个可整除元素的子数组](https://leetcode.cn/problems/k-divisible-elements-subarrays/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

这道题刚开始看可能会想到：通过前缀和计算截止每个位置可被 `p` 整除的元素个数，然后通过数学关系计算满足条件的子数组个数的方法，但对于本体而言，需要对符合上述条件的子数组进行判重，所以无论如何我们也要知道每一个子数组到底长什么样子，于是我们想到了传统艺能：暴力枚举每一个子数组 + set辅助去重的做法：

```cpp
// TLE Version
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int size = nums.size(), mnum = 0;
        vector<int> res(size, 0), pre(size);
        for (int i = 0; i < size; i++) {
            if (nums[i] % p == 0) {
                res[i]++;
            }
        }
        partial_sum(res.begin(), res.end(), pre.begin());
        pre.insert(pre.begin(), 0);
        set<vector<int>> s;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (pre[j + 1] - pre[i] <= k) {
                    vector<int> tmp;
                    for (int t = i; t <= j; t++) {
                        tmp.push_back(nums[t]);
                    }
                    s.insert(tmp);
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};
```

但我们不愿就此放弃，我们决定对上面的代码进行一些优化，首先我们注意题目中给到，长度不同的子数组一定是不同的，所以我们不难想到枚举子数组的长度，然后对于每一个长度分别判重即可，这样可以减少判重这一步的时间消耗。

```cpp
for (int len = 1; len <= size; len++) {
    set<vector<int>> s;
    int l = 0, r = size - len;
    for (int i = l; i <= r; i++) {
        if (pre[i + len] - pre[i] <= k) {
            vector<int> tmp;
            for (int t = i; t < i + len; t++) {
                tmp.push_back(nums[t]);
            }
            s.insert(tmp);
        }
    }
    ans += s.size();
}
```

#### 复杂度分析

- 时间复杂度：通过前缀和预处理整个数组的复杂度为 _O(n)_，枚举子数组长度进行处理的复杂度为 _O(n * m^2)_，set去重部分的复杂度为 _O(logm)_，总的时间复杂度为 _O(n * m^2logm)_，实话说我也不知道这题咋过的，还得是归功于数据量比较小吧。

- 空间复杂度：前缀和数组的复杂度为 _O(n)_ ，set的复杂度为 _O(mlogm)_

这个做法能过就感觉挺离奇的，复杂度也有点不会分析了qwq，赛后翻了翻题解好像可以用字典树或者哈希做，等我研究透了再来这边更新吧（挖坑 + 1），但更加离奇的事情出现了，我这个做法目前在LeetCode的C++提交中的执行用时和内存消耗都超越了100%的用户，我才是因为没有多少人选择赛后再把这个题提交一遍吧orz

### [第四题 字符串的总引力](https://leetcode.cn/problems/total-appeal-of-a-string/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

这是一道典型的 **子串统计类问题**，这类问题一般可以按照每个子串的下标对所有子串进行分组，这样考虑两组 **相邻** 的分别以 `s[i]` 和 `s[i + 1]` 结尾的子串，可以将后者视为在前者的末尾添加字符 `s[i + 1]` 形成，这就是一个典型的 **动态规划** 问题了。

对于本题来说，我们用 `dp` 数组记录当前字符的加入能对目前的字符串产生多大的引力值增加，那么对于第 `i` 个字符 `s[i]` 来说，从当前位置 `i` 向前看，对于每一个位置到当前位置 `i` 所组成的子串的引力值都 + 1 ，直到遇到 `s[i]` 上一次出现的位置 `j` 为止（上一次出现过之后再往前的就不会产生新的引力值了）。所以转移方程如下：

`dp[i] = dp[i - 1] + i - s[i]上一次出现的位置`

由于题给字符串全部由小写英文字母组成，我们可以使用一个长度为26的数组来存储每个字符上一次出现的位置，初值设为-1（将-1视作一个虚空位置，每一个字符都在这个虚空位置出现过，这样就不用讨论s[i]没有出现过的情况了）

```cpp
vector<int> idx(26, -1);
for (int i = 0; i < size; i++) {
    dp[i + 1] = dp[i] + i - idx[s[i] - 'a'];
    idx[s[i] - 'a'] = i;
}
```

#### 复杂度分析

- 时间复杂度：显而易见，我们只对题给字符串进行了一次遍历操作，以字符串的位数为 _n_ 的话, 复杂度为 _O(n)_

- 空间复杂度：dp数组的空间复杂度为 _O(n)_，idx数组为 _O(1)_，总的空间复杂度为 _O(n)_

## 完整AC代码

```cpp
// 第一题 移除指定数字得到的最大结果
class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans;
        int size = number.size();
        for (int i = 0; i < size; i++) {
            if (number[i] == digit) {
                string tmp = number;
                tmp.erase(tmp.begin() + i);
                ans = max(tmp, ans);
            }
        }
        return ans;
    }
};

// 第二题 必须拿起的最小连续卡牌数
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < size; i++) {
            if (mp.find(cards[i]) == mp.end()) {
                vector<int> tmp(1, i);
                mp.insert(make_pair(cards[i], tmp));
            }
            else {
                mp.find(cards[i])->second.push_back(i);
            }
        }
        int ans = 1e5 + 1;
        for (auto &it : mp) {
            int vsize = it.second.size();
            for (int i = 0; i < vsize - 1; i++) {
                ans = min(ans, it.second[i + 1] - it.second[i] + 1);
            }
        }
        if (ans > 1e5) {
            ans = -1;
        }
        return ans;
    }
};

// 第三题 含最多 K 个可整除元素的子数组
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int size = nums.size(), mnum = 0;
        vector<int> res(size, 0), pre(size);
        for (int i = 0; i < size; i++) {
            if (nums[i] % p == 0) {
                res[i]++;
            }
        }
        partial_sum(res.begin(), res.end(), pre.begin());
        pre.insert(pre.begin(), 0);
        int ans = 0;
        for (int len = 1; len <= size; len++) {
            set<vector<int>> s;
            int l = 0, r = size - len;
            for (int i = l; i <= r; i++) {
                if (pre[i + len] - pre[i] <= k) {
                    vector<int> tmp;
                    for (int t = i; t < i + len; t++) {
                        tmp.push_back(nums[t]);
                    }
                    s.insert(tmp);
                }
            }
            ans += s.size();
        }
        return ans;
    }
};

// 第四题 字符串的总引力
// Tutorial Version
class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int size = s.size();
        vector<int> idx(26, -1);
        vector<long long> dp(size + 1, 0);
        for (int i = 0; i < size; i++) {
            dp[i + 1] = dp[i] + i - idx[s[i] - 'a'];
            idx[s[i] - 'a'] = i;
        }
        for (int i = 1; i <= size; i++) {
            ans += dp[i];
        }
        return ans;
    }
};
```
