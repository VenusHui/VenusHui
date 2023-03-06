// 2373. 矩阵中的局部最大值
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<int>> ans(size - 2, vector<int>(size - 2));
        for (int i = 0; i < size - 2; i++) {
            for (int j = 0; j < size - 2; j++) {
                for (int k = 0; k < 9; k++) {
                    ans[i][j] = max(ans[i][j], grid[i + k / 3][j + k % 3]);
                }
            }
        }
        return ans;
    }
};