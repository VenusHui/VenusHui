// 面试题 01.09. 字符串轮转
class Solution {
public:
  bool isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) {
      return false;
    } else if (s1.size() == 0) {
      return true;
    }
    string s = s2 + s2;
    int size = s1.size();
    int index = 0;
    bool flag = false;
    for (int i = 0; i < 2 * size; i++) {
      if (s1[index] == s[i]) {
        flag = true;
        index++;
        if (index == size) {
          break;
        }
      } else {
        index = 0;
        flag = false;
      }
    }
    return index == size && flag;
  }
};