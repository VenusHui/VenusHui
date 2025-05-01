// 2546. 执行逐位运算使字符串相等
class Solution {
public:
  bool makeStringsEqual(string s, string target) {
    if (s == target)
      return true;
    int n = s.size();
    bool ans = true;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        flag++;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (target[i] == '1') {
        flag++;
        break;
      }
    }
    return flag == 2;
  }
};