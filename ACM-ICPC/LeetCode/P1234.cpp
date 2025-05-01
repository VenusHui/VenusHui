// 1234. 替换子串得到平衡字符串
class Solution {
public:
  int balancedString(string s) {
    int size = s.size(), len = s.size() / 4;
    map<char, int> mp;
    for (auto &e : s)
      mp[e]++;
    int ans = 0x3f3f3f3f;
    if (mp['Q'] <= len && mp['W'] <= len && mp['E'] <= len && mp['R'] <= len)
      return 0;
    for (int l = 0, r = 0; l < size; l++) {
      while (r < size && !(mp['Q'] <= len && mp['W'] <= len && mp['E'] <= len &&
                           mp['R'] <= len)) {
        mp[s[r]]--;
        r++;
      }
      if (!(mp['Q'] <= len && mp['W'] <= len && mp['E'] <= len &&
            mp['R'] <= len))
        break;
      ans = min(ans, r - l);
      mp[s[l]]++;
    }
    return ans;
  }
};