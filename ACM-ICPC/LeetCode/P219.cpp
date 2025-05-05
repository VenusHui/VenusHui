// 219. 存在重复元素
// 方法1. 滑动窗口（参考题解
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int size = nums.size();
    unordered_set<int> set;
    for (int i = 0; i < size; i++) {
      if (i > k) {
        set.erase(nums.at(i - k - 1));
      }
      if (set.count(nums.at(i))) // count方法是返回set中所给参数值的个数
      {
        return true;
      }
      set.emplace(nums.at(i));
    }
    return false;
  }
};

// 方法2. 哈希集合（参考思路
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int size = nums.size();
    unordered_map<int, int> dictionary;
    for (int i = 0; i < size; i++) {
      if (dictionary.count(nums.at(i))) {
        if (abs(dictionary[nums.at(i)] - i) <= k) {
          return true;
        }
        dictionary[nums.at(i)] = i;
      }
      dictionary.emplace(nums.at(i), i);
    }
    return false;
  }
};