// 1139. 最大的以 1 为边界的正方形
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> right(n + 1, vector<int>(m + 1)), down(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    right[i + 1][j + 1] = right[i + 1][j] + grid[i][j];
                    down[i + 1][j + 1] = down[i][j + 1] + grid[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1]) {
                    int len = min(right[i][j], down[i][j]);
                    while (right[i - len + 1][j] < len || down[i][j - len + 1] < len) len--;
                    ans = max(ans, len);
                }
            }
        }
        return ans * ans;
    }
};