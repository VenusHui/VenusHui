class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -0x3f3f3f3f)));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0][0] = coins[0][0];
                    dp[0][0][1] = 0;
                    dp[0][0][2] = 0;
                }
                else if (i == 0) {
                    dp[i][j][0] = dp[i][j - 1][0] + coins[i][j];
                    dp[i][j][1] = max(dp[i][j - 1][1] + coins[i][j], dp[i][j - 1][0]);
                    dp[i][j][2] = max(dp[i][j - 1][2] + coins[i][j], dp[i][j - 1][1]);
                }
                else if (j == 0) {
                    dp[i][j][0] = dp[i - 1][j][0] + coins[i][j];
                    dp[i][j][1] = max(dp[i - 1][j][1] + coins[i][j], dp[i - 1][j][0]);
                    dp[i][j][2] = max(dp[i - 1][j][2] + coins[i][j], dp[i - 1][j][1]);
                }
                else {
                    dp[i][j][0] = max(dp[i][j - 1][0] + coins[i][j], dp[i - 1][j][0] + coins[i][j]);
                    dp[i][j][1] = max(max(dp[i][j - 1][1] + coins[i][j], dp[i][j - 1][0]), max(dp[i - 1][j][1] + coins[i][j], dp[i - 1][j][0]));
                    dp[i][j][2] = max(max(dp[i][j - 1][2] + coins[i][j], dp[i][j - 1][1]), max(dp[i - 1][j][2] + coins[i][j], dp[i - 1][j][1]));
                }
            }
        }
        return max(dp[m - 1][n - 1][0], max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]));
    }
};