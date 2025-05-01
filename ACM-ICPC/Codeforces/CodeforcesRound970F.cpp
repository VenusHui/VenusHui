/**
 * @platform: Codeforces
 * @problem: CodeforcesRound970F
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-02
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int mod = 1e9 + 7;
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = (pre[i - 1] + a[i - 1]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans = (ans + (pre[n] - pre[i + 1] + mod) % mod * a[i]) % mod;
    }
    auto fast_power = [&](ll x, ll k) {
      ll res = 1 % mod, t = x % mod;
      while (k) {
        if (k & 1)
          res = res * t % mod;
        t = t * t % mod;
        k >>= 1;
      }
      return res;
    };
    auto fmod = [&](ll x, ll y) {
      return ((x % mod) * fast_power(y, mod - 2)) % mod;
    };
    cout << fmod(ans, (n - 1) * n / 2) << '\n';
  }

  return 0;
}