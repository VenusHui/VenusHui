// 38. 外观数列
// 模拟
class Solution {
public:
  string countAndSay(int n) {
    string ans = "1", temp;
    for (int i = 0; i < n - 1; i++) {
      temp.clear();
      int times = 1;
      char pre = ans[0], num;
      for (unsigned int j = 1; j < ans.size(); j++) {
        if (ans[j] == pre) {
          times++;
        } else {
          num = '0' + times;
          temp.push_back(num);
          temp.push_back(pre);
          times = 1;
          pre = ans[j];
        }
      }
      if (times != 0) {
        num = '0' + times;
        temp.push_back(num);
        temp.push_back(pre);
      }
      ans = temp;
    }
    return ans;
  }
};