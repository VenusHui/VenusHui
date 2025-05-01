// 1539. 第 k 个缺失的正整数
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    if (arr[0] > k) {
      return k;
    }
    int l = 0, r = arr.size();
    while (l < r) {
      int m = (l + r) >> 1;
      int x = m < arr.size() ? arr[m] : 2001;
      if (x - m - 1 >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1];
  }
};
