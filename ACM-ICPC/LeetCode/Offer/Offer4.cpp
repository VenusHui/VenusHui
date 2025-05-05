// 剑指 Offer 04. 二维数组中的查找
class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();
    if (m == 0)
      return false;
    pair<int, int> cnt = make_pair(0, m - 1);
    while (cnt.first < n && cnt.second >= 0) {
      if (matrix[cnt.first][cnt.second] == target)
        return true;
      if (matrix[cnt.first][cnt.second] > target)
        cnt.second--;
      else
        cnt.first++;
    }
    return false;
  }
};