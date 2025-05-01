// 剑指 Offer 10- II. 青蛙跳台阶问题
class Solution {
private:
  const int mod = 1e9 + 7;

public:
  int numWays(int n) {
    if (n == 0 || n == 1)
      return 1;
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    return dp[n] % mod;
  }
};