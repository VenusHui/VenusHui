// 34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans(2, -1);
    int size = nums.size();
    if (size == 0) {
      return ans;
    }
    int l = 0, r = size - 1;
    while (l < r) {
      int m = (r - l + 1) / 2 + l;
      if (nums[m] <= target) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (nums[l] == target) {
      ans[1] = l;
    }
    l = 0, r = size - 1;
    while (l < r) {
      int m = (r - l) / 2 + l;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (nums[l] == target) {
      ans[0] = l;
    }
    return ans;
  }
};