// 2535. 数组元素和与数字和的绝对差
class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    int sum1 = 0, sum2 = 0;
    for (auto &e : nums) {
      sum1 += e;
      while (e) {
        sum2 += e % 10;
        e /= 10;
      }
    }
    return abs(sum1 - sum2);
  }
};