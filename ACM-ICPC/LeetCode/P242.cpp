// 242. 有效的字母异位词
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> res(26);
    for (auto &it : s) {
      res[it - 'a']++;
    }
    for (auto &it : t) {
      res[it - 'a']--;
    }
    for (auto &it : res) {
      if (it != 0) {
        return false;
      }
    }
    return true;
  }
};