// 1464. 数组中两元素的最大乘积
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int size = nums.size();
    int tmp1 = nums[0], tmp2 = nums[1];
    int ans = (tmp1 - 1) * (tmp2 - 1);
    for (int i = 2; i < size; i++) {
      if (nums[i] > min(tmp1, tmp2)) {
        if (tmp1 <= tmp2) {
          tmp1 = nums[i];
          ans = (tmp2 - 1) * (nums[i] - 1);
        } else {
          tmp2 = nums[i];
          ans = (tmp1 - 1) * (nums[i] - 1);
        }
      }
    }
    return ans;
  }
};
