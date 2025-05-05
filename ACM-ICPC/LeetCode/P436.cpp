// 436. 寻找右区间
class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int size = intervals.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++) {
      intervals[i].push_back(i);
    }
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    for (int i = 0; i < size; i++) {
      if (intervals[size - 1][0] < intervals[i][1]) {
        ans[intervals[i][2]] = -1;
        continue;
      }
      int l = 0, r = size - 1;
      while (l < r) {
        int m = (l + r) >> 1;
        if (intervals[m][0] < intervals[i][1]) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      ans[intervals[i][2]] = intervals[l][2];
    }
    return ans;
  }
};