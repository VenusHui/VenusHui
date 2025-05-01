// 剑指 Offer 05. 替换空格
class Solution {
public:
  string replaceSpace(string s) {
    string ans;
    for (auto &e : s) {
      if (e == ' ')
        ans += "%20";
      else
        ans += e;
    }
    return ans;
  }
};