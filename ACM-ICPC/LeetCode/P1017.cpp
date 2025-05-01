class Solution {
public:
  string baseNeg2(int n) {
    if (n == 0)
      return "0";
    string ans;
    while (n) {
      int r = n & 1;
      ans += r + '0';
      n -= r;
      n /= -2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};