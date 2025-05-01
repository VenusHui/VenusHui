// 1351. 统计有序矩阵中的负数
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      int l = 0, r = m - 1;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (grid[i][m] >= 0) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      if (grid[i][0] >= 0) {
        ans += m - l - 1;
      } else {
        ans += m - l;
      }
    }
    return ans;
  }
};