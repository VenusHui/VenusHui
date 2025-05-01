// 剑指 Offer 03. 数组中重复的数字
class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (auto &e : nums)
      mp[e]++;
    for (auto &e : mp) {
      if (e.second > 1) {
        return e.first;
      }
    }
    return -1;
  }
};