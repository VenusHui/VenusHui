// 剑指 Offer II 069. 山峰数组的顶部
// 枚举
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int tmp = arr.at(0);
    for (unsigned int i = 1; i < arr.size(); i++) {
      if (arr.at(i) < tmp) {
        return i - 1;
      }
      tmp = arr.at(i);
    }
    return 0;
  }
};

// 二分查找
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int left = 0, right = arr.size() - 2, mid, ans = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] < arr[mid + 1]) {
        ans = mid;
        left = mid + 1;
      } else {
        ans = mid;
        right = mid - 1;
      }
    }
    return ans;
  }
};
