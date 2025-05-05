// 1806. 还原排列的最少操作步数
class Solution {
public:
  int reinitializePermutation(int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
      perm[i] = i;
    }
    int ans = 0;
    vector<int> arr(n), tmp(n);
    arr = perm;
    do {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          tmp[i] = arr[i / 2];
        } else {
          tmp[i] = arr[n / 2 + (i - 1) / 2];
        }
      }
      arr = tmp;
      ans++;
    } while (arr != perm);
    return ans;
  }
};