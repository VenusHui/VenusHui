// 2567. 修改两个元素的最小分数
class Solution {
public:
  int minimizeSum(vector<int> &nums) {
    int size = nums.size();
    if (size < 4)
      return 0;
    sort(nums.begin(), nums.end());
    return min(min(nums[size - 3] - nums[0], nums[size - 1] - nums[2]),
               nums[size - 2] - nums[1]);
  }
};