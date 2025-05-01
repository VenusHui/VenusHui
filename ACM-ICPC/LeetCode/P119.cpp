// 119. 杨辉三角 II
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> pre(1, 1);
    if (rowIndex == 0) {
      return pre;
    }
    for (int i = 1; i <= rowIndex; i++) {
      vector<int> cnt(i + 1, 1);
      for (int j = 1; j < i; j++) {
        cnt[j] = pre[j - 1] + pre[j];
      }
      pre = cnt;
    }
    return pre;
  }
};