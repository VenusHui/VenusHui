// 1742. 盒子中小球的最大数量
class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> mp;
    for (int i = lowLimit; i <= highLimit; i++) {
      string s = to_string(i);
      int tmp = 0;
      for (auto &e : s) {
        tmp += e - '0';
      }
      mp[tmp]++;
    }
    int ans = 0;
    for (auto &i : mp) {
      ans = max(ans, i.second);
    }
    return ans;
  }
};