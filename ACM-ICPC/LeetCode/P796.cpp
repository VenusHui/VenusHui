// 796. 旋转字符串
class Solution {
public:
  bool rotateString(string s, string goal) {
    bool ans = false;
    int ssize = s.size(), gsize = goal.size();
    if (ssize != gsize) {
      return false;
    }
    for (int i = 0; i < ssize; i++) {
      ans = true;
      for (int j = i, k = 0; j < ssize, k < gsize; j++, k++) {
        if (s[j] != goal[k]) {
          ans = false;
          break;
        }
        if (j == ssize - 1) {
          j = -1;
        }
      }
      if (ans) {
        return ans;
      }
    }
    return false;
  }
};