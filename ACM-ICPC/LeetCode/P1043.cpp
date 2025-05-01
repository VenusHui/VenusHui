// 1043. 分隔数组以得到最大和
class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int tmp = arr[i - 1];
      for (int j = 0; j < k; j++) {
        if (i > j) {
          tmp = max(tmp, arr[i - j - 1]);
          dp[i] = max(dp[i], dp[i - j - 1] + (j + 1) * tmp);
        }
      }
    }
    return dp[n];
  }
};