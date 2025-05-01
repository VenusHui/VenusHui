// 300. 最长递增子序列
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, dp[i]);
    return ans;
  }
};