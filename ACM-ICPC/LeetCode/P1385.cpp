// 1385. 两个数组间的距离值
class Solution {
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int ans = 0;
    int size1 = arr1.size(), size2 = arr2.size();
    for (int i = 0; i < size1; i++) {
      bool flag = true;
      for (int j = 0; j < size2; j++) {
        if (abs(arr1[i] - arr2[j]) <= d) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans++;
      }
    }
    return ans;
  }
};