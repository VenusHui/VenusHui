// 485. 最大连续 1 的个数
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ans = 0, tmp = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == 1) {
        tmp++;
        if (i == size - 1 || nums[i + 1] != 1) {
          ans = max(ans, tmp);
          tmp = 0;
        }
      }
    }
    return ans;
  }
};