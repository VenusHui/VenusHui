// 9. 回文数
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string s, t;
    while (x) {
      s += x % 10 + '0';
      x /= 10;
    }
    t = s, reverse(t.begin(), t.end());
    return s == t;
  }
};