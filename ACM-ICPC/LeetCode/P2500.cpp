// 2500. 删除每行中的最大值
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& i : grid) {
            sort(i.begin(), i.end(), [&] (int& a, int& b) {
                return a > b;
            });
        }
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp = max(tmp, grid[j][i]);
            }
            ans += tmp;
        }
        return ans;
    }
};