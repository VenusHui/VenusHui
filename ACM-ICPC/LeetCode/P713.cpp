// 713. 乘积小于 K 的子数组
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int size = nums.size(), ans = 0;
    int cnt = 1, l = 0, r;
    for (r = 0; r < size; r++) {
      cnt *= nums[r];
      while (l <= r && cnt >= k) {
        cnt /= nums[l++];
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
