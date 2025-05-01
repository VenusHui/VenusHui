// 69. x 的平方根
class Solution {
public:
  int mySqrt(int x) {
    long long l = 0, r = x;
    while (l < r) {
      long long m = (l + r + 1) >> 1;
      if (m * m <= x) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};