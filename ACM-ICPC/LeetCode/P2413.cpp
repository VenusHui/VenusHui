// 2413. 最小偶倍数
class Solution {
public:
  int smallestEvenMultiple(int n) {
    if (n % 2)
      return 2 * n;
    return n;
  }
};