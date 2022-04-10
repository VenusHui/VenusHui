// 55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = true;
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        for (int i = 1; i < size; i++) {
            if (i > dp[i - 1]) {
                return false;
            }
            dp[i] = max(dp[i - 1], i + nums[i]);
        }
        return true;
    }
};