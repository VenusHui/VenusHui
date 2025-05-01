// 1346. 检查整数及其两倍数是否存在
class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++) {
      int l = 0, r = size - 1;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (arr[m] <= 2 * arr[i]) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      if (arr[l] == 2 * arr[i] && l != i) {
        return true;
      }
    }
    return false;
  }
};