// 441. 排列硬币
class Solution {
public:
  int arrangeCoins(int n) {
    long long l = 0, r = n;
    while (l < r) {
      long long m = (l + r + 1) >> 1;
      if ((1 + m) * m / 2 <= n) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return static_cast<int>(l);
  }
};