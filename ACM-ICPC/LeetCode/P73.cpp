// 73. 矩阵置零
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<bool> row(n), col(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          row[i] = true;
          col[j] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (row[i]) {
        for (int j = 0; j < m; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int j = 0; j < m; j++) {
      if (col[j]) {
        for (int i = 0; i < n; i++) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};