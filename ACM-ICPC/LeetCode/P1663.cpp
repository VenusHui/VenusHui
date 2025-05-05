// 1663. 具有给定数值的最小字符串
class Solution {
public:
  string getSmallestString(int n, int k) {
    k -= n;
    vector<int> res(n, 'a');
    for (int i = n - 1; i >= 0 && k > 0; i--) {
      if (k - 25 >= 0)
        res[i] += 25, k -= 25;
      else
        res[i] += k, k -= k;
    }
    string ans;
    for (int i = 0; i < n; i++)
      ans += static_cast<char>(res[i]);
    return ans;
  }
};