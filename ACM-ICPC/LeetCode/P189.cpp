// 189. 轮转数组
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    k = k % size;
    vector<int> res;
    for (int i = k - 1; i != -1; i--) {
      res.push_back(nums.at(size - i - 1));
    }
    for (int i = size - k - 1; i != -1; i--) {
      nums.at(i + k) = nums.at(i);
    }
    for (int i = 0; i < k; i++) {
      nums.at(i) = res.at(i);
    }
  }
};