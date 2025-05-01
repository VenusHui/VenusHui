// 2485. 找出中枢整数
class Solution {
public:
  int pivotInteger(int n) {
    vector<int> res(n), pre(n);
    for (int i = 0; i < n; i++) {
      res[i] = i + 1;
    }
    partial_sum(res.begin(), res.end(), pre.begin());
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (pre[i] == pre[n - 1] - (i == 0 ? 0 : pre[i - 1])) {
        ans = res[i];
      }
    }
    return ans;
  }
};