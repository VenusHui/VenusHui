// 891. 子序列宽度之和
class Solution {
  typedef long long ll;

private:
  const int mod = 1e9 + 7;

public:
  int sumSubseqWidths(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<ll> res(size);
    ll tmp = 1;
    for (int i = 0; i < size; i++) {
      res[i] = tmp % mod;
      tmp = (tmp * 2) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < size; i++) {
      ans = (ans + (res[i] - 1) * nums[i]) % mod;
      ans = (ans - (res[size - i - 1] - 1) * nums[i]) % mod;
    }
    return static_cast<int>(ans);
  }
};