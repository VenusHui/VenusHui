// 1704. 判断字符串的两半是否相似
class Solution {
public:
  bool halvesAreAlike(string s) {
    string res = "aeiouAEIOU";
    int ans = 0, size = s.size();
    for (int i = 0; i < size / 2; i++) {
      for (auto &e : res) {
        if (e == s[i]) {
          ans++;
        }
      }
    }
    for (int i = size / 2; i < size; i++) {
      for (auto &e : res) {
        if (e == s[i]) {
          ans--;
        }
      }
    }
    return ans == 0;
  }
};