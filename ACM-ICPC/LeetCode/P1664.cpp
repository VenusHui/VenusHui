// 1664. 生成平衡数组的方案数
class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int ans = 0, n = nums.size();
    vector<int> odd(n), even(n);
    for (int i = 0; i < n; i++) {
      if (i)
        odd[i] = odd[i - 1], even[i] = even[i - 1];
      if (i % 2 != 0)
        odd[i] += nums[i];
      else
        even[i] += nums[i];
    }
    if (even[n - 1] - even[0] == odd[n - 1] - odd[0])
      ans++;
    for (int i = 1; i < n; i++) {
      if (odd[n - 1] - odd[i] + even[i - 1] ==
          odd[i - 1] + even[n - 1] - even[i])
        ans++;
    }
    return ans;
  }
};