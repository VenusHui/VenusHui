// 1590. 使数组和能被 P 整除
class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int num = 0, size = nums.size();
    for (auto &e : nums)
      num = (num + (e % p)) % p;
    if (!num)
      return 0;
    vector<int> pre(size + 1);
    for (int i = 1; i <= size; i++) {
      pre[i] = (pre[i - 1] + nums[i - 1]) % p;
    }
    map<int, vector<int>> mp;
    for (int i = 1; i <= size; i++)
      mp[pre[i]].push_back(i);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < size; i++) {
      int tar = (pre[i] + num) % p;
      for (auto &e : mp[tar]) {
        ans = min(ans, e - i > 0 ? e - i : 0x3f3f3f3f);
      }
    }
    if (ans == 0x3f3f3f3f || ans == size)
      return -1;
    return ans;
  }
};