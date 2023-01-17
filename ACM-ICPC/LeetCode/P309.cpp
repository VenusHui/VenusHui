// 309. 最佳买卖股票时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size + 1, vector<int>(2));
        dp[0][0] = 0;
        dp[1][0] = 0, dp[1][1] = -1 * prices[0];
        for (int i = 2; i <= size; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
        }
        return dp[size][0];
    }
};