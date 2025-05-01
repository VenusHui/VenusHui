/**
 * @platform: AcWing
 * @problem: P870
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int mod = 1e9 + 7;
  function<vector<pair<int, int>>(int)> get_prime_fact = [&](int n) {
    vector<pair<int, int>> res;
    for (int i = 2; i <= n / i; i++) {
      if (n % i == 0) {
        int s = 0;
        while (n % i == 0) {
          n /= i;
          s++;
        }
        res.push_back({i, s});
      }
    }
    if (n > 1)
      res.push_back({n, 1});
    return res;
  };
  int t;
  cin >> t;
  map<int, int> mp;
  while (t--) {
    int num;
    cin >> num;
    auto prime_fact = get_prime_fact(num);
    for (auto &e : prime_fact) {
      mp[e.first] += e.second;
    }
  }
  ll ans = 1;
  for (auto &e : mp) {
    ans = ans * (e.second + 1) % mod;
  }
  cout << ans << '\n';

  return 0;
}
