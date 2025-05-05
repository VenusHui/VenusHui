// 2309. 兼具大小写的最好英文字母
class Solution {
public:
  string greatestLetter(string s) {
    string ans;
    map<char, int> mp;
    for (auto &e : s)
      mp[e]++;
    for (int i = 25; i >= 0; i--) {
      if (mp['a' + i] && mp['A' + i]) {
        ans += static_cast<char>('A' + i);
        break;
      }
    }
    return ans;
  }
};