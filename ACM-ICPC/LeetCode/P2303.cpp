// 2303. 计算应缴税款总额
class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    int pre = 0;
    double ans = 0;
    for (auto &e : brackets) {
      if (income >= e[0]) {
        ans += (e[0] - pre) * e[1] / 100.0;
        pre = e[0];
      } else {
        ans += (income - pre) * e[1] / 100.0;
        break;
      }
    }
    return ans;
  }
};