// 2501. 数组中最长的方波
class Solution {
  typedef long long ll;

public:
  int longestSquareStreak(vector<int> &nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int ans = -1;
    function<bool(int)> check = [&](int num) {
      int l = 0, r = size - 1;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= num) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      return nums[l] == num;
    };
    for (int i = 0; i < size; i++) {
      int tmp = 0;
      ll tar = nums[i];
      while (check(static_cast<int>(tar)) && tar <= 1e5 + 1) {
        tar *= tar;
        tmp++;
      }
      if (tmp > 1) {
        ans = max(ans, tmp);
      }
    }
    return ans;
  }
};