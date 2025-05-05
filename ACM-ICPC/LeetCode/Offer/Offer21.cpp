// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    vector<int> ans;
    for (auto &e : nums)
      if (e % 2)
        ans.push_back(e);
    for (auto &e : nums)
      if (!(e % 2))
        ans.push_back(e);
    return ans;
  }
};

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    int n = nums.size();
    int l = -1, r = n;
    while (l < r) {
      do
        l++;
      while (l < r && nums[l] % 2 != 0);
      do
        r--;
      while (l < r && nums[r] % 2 == 0);
      if (l < r)
        swap(nums[l], nums[r]);
    }
    return nums;
  }
};