// 45. 跳跃游戏 II
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        const int maxNum = 1e9 + 1;
        vector<int> dp(size, maxNum);
        dp[0] = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j <= i + nums[i] && j < size; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[size - 1];
    }
};