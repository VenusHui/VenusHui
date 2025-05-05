// 670. 最大交换
class Solution {
public:
  int maximumSwap(int num) {
    vector<int> res;
    int maxn = 0, ans = num;
    while (num) {
      maxn = max(maxn, num % 10);
      res.push_back(num % 10);
      num /= 10;
    }
    reverse(res.begin(), res.end());
    int size = res.size();
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        swap(res[i], res[j]);
        int tmp = 0;
        for (int t = 0; t < size; t++) {
          tmp = tmp * 10 + res[t];
        }
        ans = max(ans, tmp);
        swap(res[i], res[j]);
      }
    }
    return ans;
  }
};