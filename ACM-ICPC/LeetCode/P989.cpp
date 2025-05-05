// 989. 数组形式的整数加法
class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    vector<int> ans;
    int size = num.size();
    int pos = size - 1;
    bool flag = false;
    while (k && pos != -1) {
      int tmp = k % 10;
      if (tmp + num[pos] + flag < 10) {
        ans.insert(ans.begin(), tmp + num[pos] + flag);
        flag = false;
      } else {
        ans.insert(ans.begin(), tmp + num[pos] + flag - 10);
        flag = true;
      }
      k /= 10;
      pos--;
    }
    if (k == 0 && pos != -1) {
      while (pos != -1) {
        if (num[pos] + flag < 10) {
          ans.insert(ans.begin(), num[pos] + flag);
          flag = false;
        } else {
          ans.insert(ans.begin(), num[pos] + flag - 10);
          flag = true;
        }
        pos--;
      }
    } else if (k != 0 && pos == -1) {
      while (k) {
        int tmp = k % 10;
        if (tmp + flag < 10) {
          ans.insert(ans.begin(), tmp + flag);
          flag = false;
        } else {
          ans.insert(ans.begin(), tmp + flag - 10);
          flag = true;
        }
        k /= 10;
      }
    }
    if (flag)
      ans.insert(ans.begin(), 1);
    return ans;
  }
};