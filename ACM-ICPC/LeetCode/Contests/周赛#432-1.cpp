class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    if (j % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            else {
                for (int j = m - 1; j >= 0; j--) {
                    if (j % 2 == 1) {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};