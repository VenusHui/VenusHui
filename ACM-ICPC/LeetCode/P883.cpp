// 883. 三维形体投影面积
class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int ans = 0;
    int size = grid.size();
    for (int i = 0; i < size; i++) {
      int tmpx = 0, tmpy = 0;
      for (int j = 0; j < size; j++) {
        if (grid[i][j]) {
          ans++;
        }
        tmpx = max(tmpx, grid[i][j]);
        tmpy = max(tmpy, grid[j][i]);
      }
      ans += tmpx + tmpy;
    }
    return ans;
  }
};