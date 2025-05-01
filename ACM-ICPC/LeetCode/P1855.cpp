// 1855. 下标对中的最大距离
class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int ans = 0;
    int size1 = nums1.size(), size2 = nums2.size();
    for (int i = 0; i < size1; i++) {
      int l = 0, r = size2 - 1;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (nums2[m] >= nums1[i]) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      ans = max(ans, l - i);
    }
    return ans;
  }
};