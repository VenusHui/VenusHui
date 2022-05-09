// 6059. 检查是否有合法括号字符串路径
// Tutorial Version
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(n + m + 1)));
        if (grid[0][0] == ')') {
            return false;
        }
        dp[0][0][1] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= i + j + 1; k++) {
                    if (dp[i][j][k]) {
                        if (i + 1 < n) {
                            int cnt = k + (grid[i + 1][j] == '(' ? 1 : -1);
                            if (cnt >= 0) {
                                dp[i + 1][j][cnt] = true;
                            }
                        }
                        if (j + 1 < m) {
                            int cnt = k + (grid[i][j + 1] == '(' ? 1 : -1);
                            if (cnt >= 0) {
                                dp[i][j + 1][cnt] = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};