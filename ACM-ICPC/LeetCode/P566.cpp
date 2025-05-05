// 566. 重塑矩阵
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int n = mat.size(), m = mat[0].size();
    if (r * c != m * n) {
      return mat;
    }
    int pos = 0;
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[pos / c][pos % c] = mat[i][j];
        pos++;
      }
    }
    return ans;
  }
};