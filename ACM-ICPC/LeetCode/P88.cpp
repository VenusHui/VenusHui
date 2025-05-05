// 88. 合并两个有序数组
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ans;
    int size1 = m, size2 = n;
    int p1 = 0, p2 = 0;
    while (p1 < size1 || p2 < size2) {
      if (p1 < size1 && p2 < size2) {
        if (nums1[p1] <= nums2[p2]) {
          ans.push_back(nums1[p1++]);
        } else {
          ans.push_back(nums2[p2++]);
        }
      } else if (p1 == size1 && p2 < size2) {
        ans.push_back(nums2[p2++]);
      } else if (p2 == size2 && p1 < size1) {
        ans.push_back(nums1[p1++]);
      } else {
        break;
      }
    }
    nums1 = ans;
    return;
  }
};