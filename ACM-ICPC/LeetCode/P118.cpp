// 118. 杨辉三角
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> tmp;
    tmp.push_back(1);
    ans.push_back(tmp);
    if (numRows == 1) {
      return ans;
    }
    for (int i = 1; i < numRows; i++) {
      vector<int> res(i + 1, 1);
      for (int j = 1; j < i; j++) {
        res[j] = tmp[j - 1] + tmp[j];
      }
      ans.push_back(res);
      tmp = res;
    }
    return ans;
  }
};