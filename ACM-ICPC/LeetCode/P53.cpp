// 53. 最大子数组和
// 动态规划
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size + 1);
    int ans = INT_MIN;
    for (int i = 1; i <= size; i++) {
      dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
  }
};
