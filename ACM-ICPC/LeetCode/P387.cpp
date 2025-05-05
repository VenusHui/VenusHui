// 387. 字符串中的第一个唯一字符
class Solution {
public:
  int firstUniqChar(string s) {
    int ans = 1e9 + 1, size = s.size();
    vector<pair<int, int>> res(26, make_pair(-1, 0));
    for (int i = 0; i < size; i++) {
      if (res[s[i] - 'a'].first == -1) {
        res[s[i] - 'a'].first = i;
      }
      res[s[i] - 'a'].second++;
    }
    for (int i = 0; i < 26; i++) {
      if (res[i].second == 1) {
        ans = min(ans, res[i].first);
      }
    }
    if (ans > 1e9) {
      return -1;
    } else {
      return ans;
    }
  }
};