// 868. 二进制间距
class Solution {
public:
  int binaryGap(int n) {
    int ans = 0, cnt = 0, pre = -1;
    vector<int> res;
    while (n) {
      res.push_back(n % 2);
      n /= 2;
    }
    int size = res.size();
    for (int i = 0; i < size; i++) {
      if (res[i] == 1) {
        if (pre == -1) {
          pre = i;
        } else {
          ans = max(ans, i - pre);
          pre = i;
        }
      }
    }
    return ans;
  }
};