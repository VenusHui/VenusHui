### 题目分析

对于题目给定的矩阵链，我们需要找到一个这些矩阵相乘的顺序，使得总进行的乘法次数最少。

这里的乘法是指数与数之间进行的乘法，例如一个 `m * n` 的矩阵和 `n * p` 的矩阵相乘，进行的乘法次数为 `m * n * p` 次。

### 算法思想

我们可以按照[之前提到过的思路](./assignment.md/#please-describe-your-understanding-of-dynamic-programming)来分析这一问题

由于矩阵乘法的性质，很显然这是一个具有子问题重叠性的问题，即我们可以在所给矩阵链 `[1, n]` 的任意位置 `k, 其中1 < k < n` 处进行划分，则原问题被划分为两个规模更小的子问题 `[1, k]` 和 `[k + 1, n]`。

这样我们就可以 **递归** 的解决这个问题：

```cpp
int calc(int l, int r) {
    for (int k = l; i < r; k++) {
        ans = min(ans, calc(l, k) + calc(k + 1, r) + p[l - 1] * p[k] * p[r]);
    }
    return ans;
}
```

那么最终的答案应该是 `calc(1, n)`

但递归依旧存在之前提到过的大量重复的问题，上述算法的时间复杂度甚至为指数级别，所以我们可以使用 **记忆化搜索** 来优化递归的过程：

我们使用一个二维数组 `vector<vector<int>> dp` 来存储搜索到的结果，并将所有值初始化为 `-1`（-1代表这一状态还未曾搜索到） ，`dp[i][j]` 表示从第i个矩阵乘到第j个矩阵所需要的最小乘法次数，则有：

```cpp
int calc(int l, int r) {
    if(l == r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r]; // 直接使用搜索过的结果
    }
    for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], calc(l, k) + calc(k + 1, r) + p[l - 1] * p[k] * p[r]);
    }
    return dp[i][j];
}
```

那么最终的答案同样应该是 `calc(1, n)`

但记忆化搜索仍然是一个递归的过程，因为它是从区间 `[1, n]` ，也就是问题的终点开始搜索的，现在我们要利用动态规划将这一搜索过程转化为从起点向终点进行：

这一部分也就是本题的核心代码，其中dp数组的含义与前文一致：

```cpp
int matrixChainMultiplication(vector<int>& p) {
    // Calculate the minimum number of basic operations.
    int size = p.size();
    vector<vector<int>> dp(size, vector<int>(size)); // dp[i][j]表示从第i个矩阵乘到第j个矩阵所需要的最小乘法次数
    for (int len = 2; len < size; len++) { // 枚举子问题的长度（1个矩阵的情况永远为0，不用考虑，所以从2开始）
        for (int l = 1; l < size - len + 1; l++) {
            int r = l + len - 1; // 计算该长度下，每一个[l, r]区间
            dp[l][r] = 1 >> 30;  // 要求最小值，所以初始化为inf
            for (int k = l; k < r; k++) { // 在该[l, r]区间内枚举一个位置 k，计算将区间分为[l, k]和[k + 1, r]所需要的最小乘法次数
                int num = dp[l][k] + dp[k + 1][r] + p[l - 1] * p[k] * p[r];
                dp[l][r] = min(dp[l][r], num); // 更新dp[l][r]
            }
        }
    }
    return dp[1][size - 1];
}
```

这里采用了十分经典的 **区间dp** 思想，将不同的区间长度作为dp的阶段，使用区间左右端点的坐标描述每个维度，每一个状态都由若干个 **包含于它且比它更小的区间** 所代表的的状态转移得到，本题的转移方程为：

$$
dp[i][j] = min_{1 < k < n}(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] \times p[k] \times p[j]), 1 \leqslant i \leqslant j \leqslant n
$$

### [完整代码](./src.cpp)