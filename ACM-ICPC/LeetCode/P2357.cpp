// 2357. 使数组中所有元素都等于零
class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int size = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++) {
      if (nums[i]) {
        int cnt = nums[i];
        for (int j = i; j < size; j++) {
          nums[j] -= cnt;
        }
        ans++;
      }
    }
    return ans;
  }
};