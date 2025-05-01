// 769. 最多能完成排序的块
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    int ans = 0, tmp = arr[0];
    int size = arr.size();
    for (int i = 0; i < size; i++) {
      tmp = max(tmp, arr[i]);
      if (tmp == i) {
        ans++;
      }
    }
    return ans;
  }
};