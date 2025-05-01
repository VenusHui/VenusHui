// 905. 按奇偶排序数组
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] % 2 == 0) {
        int tmp = nums[i];
        nums.erase(nums.begin() + i);
        nums.insert(nums.begin(), tmp);
      }
    }
    return nums;
  }
};