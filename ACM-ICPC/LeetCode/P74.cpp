// 74. 搜索二维矩阵
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int l = 0, r = n * m - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (matrix[mid / m][mid % m] <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return matrix[l / m][l % m] == target;
  }
};