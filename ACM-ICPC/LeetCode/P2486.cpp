// 2486. 追加字符以获得子序列
class Solution {
public:
  int appendCharacters(string s, string t) {
    int ans = 0;
    int tsize = t.size(), ssize = s.size();
    int pos = 0;
    for (int i = 0; i < tsize; i++) {
      bool flag = false;
      for (int j = pos; j < ssize; j++) {
        if (t[i] == s[j]) {
          flag = true;
          pos = j + 1;
          break;
        }
      }
      if (!flag) {
        ans = tsize - i;
        break;
      }
    }
    return ans;
  }
};