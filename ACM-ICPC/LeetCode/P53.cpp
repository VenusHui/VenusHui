// 53. 最大子数组和
// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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