// 1. 两数之和
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums.at(i) + nums.at(j) == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};