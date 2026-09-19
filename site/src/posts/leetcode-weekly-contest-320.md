---
title: Leetcode第320场周赛1-3题题解
date: 2022-11-20
tags: [leetcode, contest-solution]
summary: 比赛时间：2022/11/20 10:30-12:00，排名：1776/5678
draft: true
lang: zh
---

> 这次是真·好久不见，从今天开始VenusHui's Blog的题解栏目要坚持更新啦！

![](https://fc.dianhsu.top/lc?user=VenusHui&loc=cn&req=rating)

## [Leetcode第320场周赛](https://leetcode.cn/contest/weekly-contest-320/)

### [第一题 数组中不等三元组的数目](https://leetcode.cn/problems/number-of-unequal-triplets-in-array/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析：

根据数据范围，我们显然可以暴力用 `O(n^3)` 的复杂度进行遍历找出每个符合题目条件的三元组并统计数目

#### 复杂度分析：

- 时间复杂度 `O(n^3)`
- 空间复杂度 `O(1)`

#### AC代码

```cpp
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (nums[i] != nums[j]) {
                    for (int k = j; k < size; k++) {
                        if (nums[k] != nums[i] && nums[k] != nums[j]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

### [第二题 二叉搜索树最近节点查询](https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

由于题给的是二叉搜索树，所以我们可以直接通过以下两步解决问题：

- 中序遍历的方式获取包含所有节点值的有序数组（虽然赛时我是先序遍历再排序，，真蠢！）
- 二分在该有序数组中查找每一个询问的答案

需要注意的是：对于每一个询问，不能直接在二叉搜索树中进行搜索，因为这棵树不一定是平衡的，很可能出现单支树的极端情况导致TLE。

#### AC代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> res;
    inline void calc(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        calc(node->left);
        calc(node->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));
        calc(root);
        sort(res.begin(), res.end());
        int size = res.size();
        for (int i = 0; i < n; i++) {
            if (queries[i] < res[0]) {
                ans[i][0] = -1;
            }
            else {
                int l = 0, r = size - 1;
                while (l < r) {
                    int m = (l + r + 1) >> 1;
                    if (res[m] <= queries[i]) {
                        l = m;
                    }
                    else {
                        r = m - 1;
                    }
                }
                ans[i][0] = res[l];
            }
            if (queries[i] > res[size - 1]) {
                ans[i][1] = -1;
            }
            else {
                int l = 0, r = size - 1;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (res[m] < queries[i]) {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }
                ans[i][1] = res[l];
            }
        }
        return ans;
    }
};
```

### [第三题 到达首都的最少油耗](https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/)

> 题目描述 / 样例 / 数据范围见原题链接，以下为个人题解。

#### 题目分析

- 为使消耗的汽油最少，我们应该从树的叶子节点出发开始处理，因为只有叶子节点才一定不会被其他节点搭到顺风车。

  明确贪心的条件之后，我们可以使用 **dfs** 的方式进行搜索，**dfs** 可以确保每次处理都是从未被处理过的叶子节点开始的。

- 再计算油耗时，对于每一个节点来说，将该节点的所有人运送到下一节点的油耗只与该节点的人流量有关，所以在 **dfs** 的时候我们还需要记录当前处理的节点会给下一个到达节点带去多少人流量，也就是说 **dfs** 函数需要返回的是该节点的人流量，同时油耗可以通过该节点的人流量动态得出，这个动态得出的过程也被称作 **树上dp**。

#### AC代码

```cpp
class Solution {
typedef long long ll;
public:
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> mp(n + 1);
        for (int i = 0; i < n; i++) {
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> vis(n + 1, false);
        vector<int> visn(n + 1, 1);
        ll ans = 0;
        function<ll(int)> dfs = [&] (int cnt) {
            if (vis[cnt]) {
                return 0;
            }
            vis[cnt] = true;
            for (auto& i : mp[cnt]) {
                visn[cnt] += dfs(i);
            }
            if (cnt) {
                if (visn[cnt] % seats == 0) {
                    ans += visn[cnt] / seats;
                }
                else {
                    ans += visn[cnt] / seats + 1;
                }
            }
            return visn[cnt];
        };
        dfs(0);
        return ans;
    }
};
```
