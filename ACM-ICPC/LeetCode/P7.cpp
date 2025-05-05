// 7. 整数反转
class Solution {
public:
  int reverse(int x) {
    string s;
    long long xx = static_cast<long long>(x);
    bool flag = false;
    if (xx < 0) {
      flag = true;
      xx *= -1;
    }
    while (xx) {
      s += char(xx % 10 + '0');
      xx /= 10;
    }
    long long ans = 0, size = s.size();
    if (size > 10 || (size == 10 && s[size - 1] >= '3'))
      return 0;
    for (int i = size - 1; i >= 0; i--)
      ans += static_cast<long long>(pow(10, size - i - 1)) *
             static_cast<long long>(s[i] - '0');
    if (ans > INT_MAX ||
        ans < static_cast<long long>(-1) * static_cast<long long>(INT_MAX))
      return 0;
    if (flag)
      ans *= -1;
    return ans;
  }
};