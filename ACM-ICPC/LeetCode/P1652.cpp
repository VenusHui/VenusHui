// 1652. 拆炸弹
class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    int size = code.size();
    vector<int> ans = code;
    for (int i = 0; i < size; i++) {
      if (k == 0) {
        ans[i] = 0;
      } else if (k > 0) {
        int tmp = 0;
        for (int j = 1; j <= k; j++) {
          tmp += code[(i + j) % size];
        }
        ans[i] = tmp;
      } else if (k < 0) {
        int tmp = 0;
        for (int j = 1; j <= -1 * k; j++) {
          tmp += code[(i - j + size) % size];
        }
        ans[i] = tmp;
      }
    }
    return ans;
  }
};