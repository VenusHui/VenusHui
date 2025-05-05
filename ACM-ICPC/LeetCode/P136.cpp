// 136. 只出现一次的数字
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (auto &e : nums)
      ans ^= e;
    return ans;
  }
};