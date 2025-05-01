// 1641. 统计字典序元音字符串的数目
class Solution {
private:
  const int maxn = 5;

public:
  int countVowelStrings(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(maxn));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < maxn; j++) {
        for (int k = 0; k <= j; k++) {
          dp[i + 1][j] += dp[i][k];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++) {
      ans += dp[n][i];
    }
    return ans;
  }
};