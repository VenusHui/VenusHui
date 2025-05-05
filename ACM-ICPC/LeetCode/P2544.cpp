// 2544. 交替数字和
class Solution {
public:
  int alternateDigitSum(int n) {
    int ans = 0, flag = 1;
    string s;
    while (n) {
      s += n % 10 + '0';
      n /= 10;
    }
    reverse(s.begin(), s.end());
    for (auto &e : s) {
      ans += (e - '0') * flag;
      flag *= -1;
    }
    return ans;
  }
};