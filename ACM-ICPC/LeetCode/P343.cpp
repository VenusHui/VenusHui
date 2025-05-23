// 343. 整数拆分
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      int curmax = 0;
      for (int j = 1; j < i; j++) {
        curmax = max(curmax, max(j * (i - j), j * dp[i - j]));
      }
      dp[i] = curmax;
    }
    return dp[n];
  }
};