## Assignment Three

|Name|Student Number|
|:----:|:----------:|
|胡锦晖|2053300|

#### Please describe your understanding of dynamic programming

我对于动态规划的理解要从问题与状态空间谈起：

对问题进行求解，实际上就是在问题对应的状态空间中进行映射与遍历。我们有递归、递推等很多种手段去遍历问题的状态空间，比如深度优先搜索算法就是递归地去遍历问题的状态空间。

而对于具有子问题重叠性的问题而言，这些做法通常是低效的，由于子问题之间的相似性，这些做法通常会多次重复计算问题的同一个状态（即同一个子问题）。以十分经典的斐波那契数列问题举例，如果我们递归的遍历该问题的状态空间：在求解 `f[i]` 的时候我们计算了 `f[i - 1]` 和 `f[i - 2]` 这两个子问题，在求 `f[i + 1]` 的时候我们又计算了 `f[i]` 和 `f[i - 1]` 这两个子问题，这里就出现了 `f[i]` 和 `f[i - 1]` 两次重复，事实上，当 `i` 越大时，重复状态的规模也就越大。

一个很有效的想法是将我们每一次计算出的结果记录下来，也就是说将我们已经遍历过的子问题的解记录下来，这就是记忆化搜索。同样是斐波那契数列问题，我们可以在求解 `f[i]` 的时将求解的 `f[i]` 与 `f[i - 1]` 、 `f[i - 2]` 记录下来，这样在求解 `f[i + 1]` 时直接使用记录过的 `f[i]` 和 `f[i - 1]` 的状态即可。

**动态规划** 的想法与记忆化搜索一样，也是将已经遍历过的问题的状态记录下来，从而对各状态维度进行 **分阶段、有顺序、无重复** 的遍历。但与记忆化搜索从问题终点递归地向问题起点递归地遍历不同，动态规划是从问题起点向问题终点一步步遍历的，这就要求用动态规划解决的问题一定要满足一些特殊的性质，从而保证这样的遍历顺序最终一定能够得到正确的答案，这两条性质便是 **无后效性** 以及 **最优子结构**。

- 无后效性：显然，因为是从起点向终点的遍历，所以我们势必不能使已经求解的子问题受到后续阶段的影响。换言之，**动态规划对于对于状态空间的遍历构成一张有向无环图，遍历顺序就是该有向无环图的一个拓扑序**，有向无环图中的结点对应问题的状态，图中的边则对应状态之间的转移。

- 最优子结构：**下一阶段的最优解一定能够由前面各阶段的子问题的最优解推出**，需要注意的是，在划分阶段的时候不能无限递归（即状态空间图不能成环）。实际上，动态规划在阶段计算完成时，只会在每个状态上保留与最终解集相关的部分信息，这些信息应该具有可重复的求解过程。

满足上述两个条件之后，动态规划只需要找到状态之间进行转移的过程与关系即可，也就是说，动态规划是将相同的计算过程作用于各个阶段的同类子问题的不同状态之上，通常使用 **状态转移方程** 来描述这一计算过程。

而状态和转移这两个动态规划算法在求解中的核心也就成了算法优化的突破口：从状态入手，有状态压缩、倍增等优化手段；从转移入手，有单调队列、斜率优化等优化手段。

#### Problem2

You are given an array prices where prices[i] is the price of a given stock on the i-th day.
Find the maximum profit you can achieve. You can only hold at most one share of the
stock at any time. After you sell your stock, you cannot buy stock on the next day (i.e.,
cooldown one day). You may not engage in multiple transactions simultaneously (i.e., you
must sell the stock before you buy again).

[完整代码：点击查看源文件](./Problem2.cpp)

核心代码：

```cpp
int size = stocks.size();
vector<vector<int>> dp(size + 1, vector<int>(2));
dp[0][0] = 0;
dp[1][0] = 0, dp[1][1] = -1 * stocks[0];
for (int i = 2; i <= size; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + stocks[i - 1]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - stocks[i - 1]);
}
cout << dp[size][0] << '\n';
```

#### Problem3

The background is the same as the previous question. On each day, you may decide to
buy and/or sell the stock. However, you can buy it then immediately sell it on the same
day (no cooling time). Find and return the maximum profit you can achieve.

[完整代码：点击查看源文件](./Problem3.cpp)

核心代码：

```cpp
int ans = 0;
int size = stocks.size();
for (int i = 0; i < size - 1; i++) {
    if (stocks[i] <= stocks[i + 1]) {
        ans += stocks[i + 1] - stocks[i];
    }
}
cout << ans << '\n';
```
