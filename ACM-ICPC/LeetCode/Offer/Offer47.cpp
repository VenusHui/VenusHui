// 剑指 Offer 47. 礼物的最大价值
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
            }
        }
        return dp[n][m];
    }
};