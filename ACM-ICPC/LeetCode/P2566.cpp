// 2566. 替换一个数字后的最大差值
class Solution {
public:
  int minMaxDifference(int num) {
    string n = to_string(num), m = to_string(num);
    int size = n.size();
    char flag = '9', minflag = '0';
    for (int i = 0; i < size; i++) {
      if (n[i] != '9') {
        flag = n[i];
        break;
      }
    }
    for (int i = 0; i < size; i++) {
      if (m[i] != '0') {
        minflag = m[i];
        break;
      }
    }
    for (int i = 0; i < size; i++) {
      if (n[i] == flag)
        n[i] = '9';
      if (m[i] == minflag)
        m[i] = '0';
    }
    return stoi(n) - stoi(m);
  }
};