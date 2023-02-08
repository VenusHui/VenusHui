// 2319. 判断矩阵是否是一个 X 矩阵
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool ans = true;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i || j == n - i - 1) {
                    if (grid[i][j] == 0) {
                        ans = false;
                        break;
                    }
                }
                else {
                    if (grid[i][j] != 0) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};