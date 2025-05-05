// 4. 寻找两个正序数组的中位数
// 双指针 O(n + m)
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    double ans = 0;
    int size1 = nums1.size(), size2 = nums2.size();
    int size = size1 + size2;
    vector<int> res;
    int i = 0, j = 0, idx = 0;
    while (i < size1 || j < size2) {
      if (j == size2 || i < size1 && nums1[i] <= nums2[j]) {
        i++, idx++;
        if (idx == size / 2 + 1 || idx == (size + 1) / 2)
          res.push_back(nums1[i - 1]);
      }
      if (i == size1 || j < size2 && nums1[i] > nums2[j]) {
        j++, idx++;
        if (idx == size / 2 + 1 || idx == (size + 1) / 2)
          res.push_back(nums2[j - 1]);
      }
    }
    for (auto &e : res) {
      ans += e;
    }
    return ans / res.size();
  }
};