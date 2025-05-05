// 367. 有效的完全平方数
class Solution {
public:
  bool isPerfectSquare(int num) {
    long long l = 1, r = num;
    while (l <= r) {
      long long m = (l + r) >> 1;
      if (m * m < num) {
        l = m + 1;
      } else if (m * m == num) {
        return true;
      } else {
        r = m - 1;
      }
    }
    return false;
  }
};