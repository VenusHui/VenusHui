// 2287. 重排字符形成目标字符串
class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    map<char, int> mps, mpt;
    for (auto &e : s) {
      mps[e]++;
    }
    for (auto &e : target) {
      mpt[e]++;
    }
    int ans = 1 << 30;
    for (auto &e : mpt) {
      ans = min(ans, mps[e.first] / e.second);
    }
    return ans >= (1 << 30) ? 0 : ans;
  }
};