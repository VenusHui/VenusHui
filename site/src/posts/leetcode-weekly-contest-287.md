---
title: Leetcode第287场周赛题解
date: 2022-04-05
tags: [leetcode, contest-solution]
summary: 比赛时间：2022/04/03 10:30-12:00，排名：2019/6811
lang: zh
---

![](https://fc.dianhsu.top/lc?user=VenusHui&loc=cn&req=rating)

> 别问为什么第75场双周赛打的早题解却写的晚，问就是打的时候第四题看都没看qwq。
>
> 最近封校白天忙着打游戏，晚上忙着emo，没怎么写题，争取明后天把双周赛的题解肝出来（即把第四题做出来...）

## [Leetcode第287场周赛](https://leetcode.cn/contest/weekly-contest-287/)

### [第一题 转化时间需要的最少操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-convert-time/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

由于是24小时制时间，数据范围有限，所以本题就是一道很常规的**模拟**。

具体的模拟思路如下：将题给的字符串转换为当前和目标时间的小时和分钟：

```cpp
int ch = (current[0] - '0') * 10 + (current[1] - '0') * 1;
int cm = (current[3] - '0') * 10 + (current[4] - '0') * 1;
int ah = (correct[0] - '0') * 10 + (correct[1] - '0') * 1;
int am = (correct[3] - '0') * 10 + (correct[4] - '0') * 1;
```

然后判断判断分钟数够不够减，如果够减则直接计算得出答案，否则需要向小时"借一位"，即加上60再计算。注意题目的数据范围中已经明确指出`current <= correct`，所以不用担心最后的答案为负的情况（虽然我的AC代码中对于这种情况直接又向上借位借了24小时，不会真的有人不读题吧不会吧不会吧不会吧...）。

#### 复杂度分析

由于数据范围有限，时间和空间复杂度均为 _O(1)_

### [第二题 找出输掉零场或一场比赛的玩家](https://leetcode.cn/problems/find-players-with-zero-or-one-losses/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

按照题目要求，我们需要找到一场比赛都没有输的的玩家以及只输掉一场比赛的玩家，即我们需要统计所有玩家输的场次数量，则可以用`map<int, int>`记录，第一关键字为玩家的编号，第二关键字为该玩家输的场次数量。

此外，由于我们需要考虑的是那些至少参加了一场比赛的玩家，所以一场比赛都没有输的玩家一定会从有胜场的玩家中产生，相似的，我们同样用一个`map<int, int>`记录，第一关键字为玩家的编号，第二关键字为该玩家获胜的的场次数量。（其实这里只需要记录获胜玩家的编号即可，但中国人总会有一种对于对称的近乎狂热的追求哈哈哈哈）

```cpp
for (int i = 0; i < size; i++) {
    if (w.find(matches[i][0]) == w.end()) {
        w.insert(make_pair(matches[i][0], 1));
    }
    else {
        w.find(matches[i][0])->second++;
    }
    if (l.find(matches[i][1]) == l.end()) {
        l.insert(make_pair(matches[i][1], 1));
    }
    else {
        l.find(matches[i][1])->second++;
    }
}
```

查找全胜玩家，只需要遍历获胜玩家的列表，并查找每一位获胜玩家在失败玩家列表中的失败场次，若未找到则该玩家确实一场未输，加入答案。

```cpp
for (map<int, int>::iterator it = w.begin(); it != w.end(); it++) {
    if (l.find(it->first) == l.end()) {
        ans[0].push_back(it->first);
    }
}
```

查找只输了一场的玩家，只需要遍历失败玩家列表，失败场次为1则加入答案。

```cpp
for (map<int, int>::iterator it = l.begin(); it != l.end(); it++) {
    if (it->second == 1) {
        ans[1].push_back(it->first);
    }
}
```

#### 复杂度分析

- 时间复杂度：

  根据上述题目分析，整个代码分为三个部分：

  - 遍历整个数组的复杂度为 _O(n)_ ，向`map`中插入元素的复杂度为 _O(logn)_，总的时间复杂度为 _O(nlogn)_。

  - 查找全胜玩家需要遍历获胜玩家列表，复杂度为 _O(n)_，并查找该玩家的失败场次，复杂度为 _O(logn)_，总的时间复杂度为 _O(nlogn)_。

  - 查找只输一场的玩家只需要遍历失败玩家列表，复杂度为 _O(n)_

综上所述，总的时间复杂度为 _O(nlogn)_。

### [第三题 每个小孩最多能分到多少糖果](https://leetcode.cn/problems/maximum-candies-allocated-to-k-children/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

二分战神曾经说，学会二分，cf 的rating至少能上2500（bushi

本题是一道非常经典的二分题目，由于每个小孩只能拿走至多一堆糖果，所以我们可以从`0`到一堆糖果的最大个数加一即`1e7 + 1`开始二分，即可得到答案。

二分的过程中只需要计算对于每个二分的值`x`，是否能够分出`k`堆糖果使得每堆的糖果数量为`x`，其实就是一个简单的除法：

```cpp
int m = (l + r) / 2;
long long num = 0;
for (int i = 0; i < size; i++) {
    num += candies[i] / m;
}
```

#### 复杂度分析

- 时间复杂度：二分过程的复杂度为 _O(logm)_，再计算是否符合要求时需要遍历整个糖果数组，复杂度为 _O(n)_，总的时间复杂度为 _O(nlogm)_，这里的`m`为一堆糖果的最大数目`1e7`

### [第四题 加密解密字符串](https://leetcode.cn/problems/encrypt-and-decrypt-strings/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

先抛开难度不谈，单单这个题干长度就有点劝退那味了，但逐步拆解下来会发现这是一道很简单的题，深吸一口气我们现在开始：

首先题目想要我们实现一个类，作用是对给定的字符串进行加密以及解密：

- 将`word1`加密：由于数据范围中已经明确说明所有 `keys[i]` 互不相同所有 `word1[i]` 都出现在 `keys` 中，所以我们可以对于 `word1`中的每一位遍历 `keys` 找到相等的下标之后将对应的 `values` 添加到答案中即可。

```cpp
for (int i = 0; i < size; i++) {
    for (int j = 0; j < ksize; j++) {
        if (word1[i] == k[j]) {
            ans += v[j];
        }
    }
}
```

- 将`word2`解密：根据题目中描述的解密过程，每次解密的分步骤可能会出现多种情况，而最后得到的字符串是多种情况的叠加，所以可以使用 **字典树** 解决（等我学完字典树就回来更新字典树做法）。但其实并不用如此大动干戈，虽然解密到加密的方向会出现多种情况，但加密到解密的过程是唯一的啊！再加上我们要求的是最后得到的字符串在`dictionary`中的个数，所以可以直接遍历整个 `dictionary`，对其中的每一个字符串都加密之后与`word2`进行对比即可得到答案。

```cpp
for (int i = 0; i < dsize; i++) {
    if (d[i].size() * 2 != size) {
        continue;
    }
    if (encrypt(d[i]) == word2) {
        ans++;
    }
}
```

这里是直接借用了之前的`encrpty()`进行加密，手动加密的版本也放到后面的[完整AC代码中了](#完整ac代码)

#### 复杂度分析

由于本题十分明显的模拟性质以及并不大的数据范围，也就没什么必要进行复杂度分析了

## 完整AC代码

```cpp
// 第一题 转化时间需要的最少操作数
class Solution {
public:
    int convertTime(string current, string correct) {
        int ch = (current[0] - '0') * 10 + (current[1] - '0') * 1;
        int cm = (current[3] - '0') * 10 + (current[4] - '0') * 1;
        int ah = (correct[0] - '0') * 10 + (correct[1] - '0') * 1;
        int am = (correct[3] - '0') * 10 + (correct[4] - '0') * 1;
        int ans = 0;
        int adh = 0, adm = 0;
        if (ch > ah || ch == ah && cm > am) {
            adh = (24 - (ch - ah - 1));
            adm = (60 + am) - cm;
        }
        else {
            adh = ah - ch;
            if (cm > am) {
                adm = (60 + am) - cm;
                adh--;
            }
            else {
                adm = am - cm;
            }
        }
        ans += adh;
        while (adm) {
            if (adm >= 15) {
                adm -= 15;
            }
            else if (adm >= 5) {
                adm -= 5;
            }
            else if (adm >= 1) {
                adm -= 1;
            }
            ans++;
        }
        return ans;
    }
};

// 第二题 找出输掉零场或一场比赛的玩家
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        int size = matches.size();
        map<int, int> w, l;
        for (int i = 0; i < size; i++) {
            if (w.find(matches[i][0]) == w.end()) {
                w.insert(make_pair(matches[i][0], 1));
            }
            else {
                w.find(matches[i][0])->second++;
            }
            if (l.find(matches[i][1]) == l.end()) {
                l.insert(make_pair(matches[i][1], 1));
            }
            else {
                l.find(matches[i][1])->second++;
            }
        }
        for (map<int, int>::iterator it = w.begin(); it != w.end(); it++) {
            if (l.find(it->first) == l.end()) {
                ans[0].push_back(it->first);
            }
        }
        for (map<int, int>::iterator it = l.begin(); it != l.end(); it++) {
            if (it->second == 1) {
                ans[1].push_back(it->first);
            }
        }
        return ans;
    }
};

// 第三题 每个小孩最多能分到多少糖果
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int size = candies.size();
        int l = 0, r = 1e7 + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            long long num = 0;
            for (int i = 0; i < size; i++) {
                num += candies[i] / m;
            }
            if (num < k) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return l;
    }
};

// 第四题 加密解密字符串
class Encrypter {
private:
    vector<char> k;
    vector<string> v;
    vector<string> d;
    int ksize, vsize, dsize;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        k = keys;
        v = values;
        d = dictionary;
        ksize = keys.size();
        vsize = values.size();
        dsize = dictionary.size();
    }

    string encrypt(string word1) {
        string ans;
        int size = word1.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < ksize; j++) {
                if (word1[i] == k[j]) {
                    ans += v[j];
                }
            }
        }
        return ans;
    }

    // 直接使用上面的encrypt()进行加密
    int decrypt(string word2) {
        int ans = 0, size = word2.size();
        for (int i = 0; i < dsize; i++) {
            if (d[i].size() * 2 != size) {
                continue;
            }
            if (encrypt(d[i]) == word2) {
                ans++;
            }
        }
        return ans;
    }

    // 手动模拟解密过程
    int decrypt(string word2) {
        int ans = 0, size = word2.size();
        for (int i = 0; i < dsize; i++) {
            if (d[i].size() != size / 2){
                continue;
            }
            bool flag = true;
            for (int j = 0; j < size / 2; j++) {
                string tmp;
                tmp += word2[j * 2];
                tmp += word2[j * 2 + 1];
                flag = false;
                for (int t = 0; t < vsize; t++) {
                    if (tmp == v[t] && k[t] == d[i][j]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
```
