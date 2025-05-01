// 1886. 判断矩阵经轮转后是否一致
class Solution {
public:
  bool findRotation(vector<vector<int>> &matrix, vector<vector<int>> &target) {
    int size = matrix.size();
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < size; j++) {
        int l = 0, r = size - 1;
        while (l < r) {
          swap(matrix[l][j], matrix[r][j]);
          l++;
          r--;
        }
      }
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      if (matrix == target) {
        return true;
      }
    }
    return false;
  }
};