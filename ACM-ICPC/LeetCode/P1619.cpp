// 1619. 删除某些元素后的数组均值
class Solution {
public:
  double trimMean(vector<int> &arr) {
    int size = arr.size();
    int del = size / 20;
    double ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = del; i < size - del; i++) {
      ans += arr[i];
    }
    ans /= (size - 2 * del);
    return ans;
  }
};