// 2283. 判断一个数的数字计数是否等于数位的值
class Solution {
public:
  bool digitCount(string num) {
    int size = num.size();
    vector<int> res(10);
    for (int i = 0; i < size; i++) {
      res[num[i] - '0']++;
    }
    bool flag = true;
    for (int i = 0; i < size; i++) {
      if (num[i] - '0' != res[i]) {
        flag = false;
        break;
      }
    }
    return flag;
  }
};