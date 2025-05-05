// 2427. 公因子的数目
class Solution {
public:
  int commonFactors(int a, int b) {
    auto calc = [&](int num) {
      map<int, int> mp;
      for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
          mp[i] = i;
          if (num / i != i) {
            mp[num / i] = 1;
          }
        }
      }
      return mp;
    };
    int ans = 0;
    map<int, int> amp = calc(a), bmp = calc(b);
    for (auto &e : amp) {
      if (bmp.count(e.first))
        ans++;
    }
    return ans;
  }
};