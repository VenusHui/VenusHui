/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#797E
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-07
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i] / k;
      a[i] = a[i] % k;
    }
    sort(a.begin(), a.end(), [&](ll &x, ll &y) { return x > y; });
    int l = 0, r = n - 1;
    while (l < r) {
      if (a[l] + a[r] >= k) {
        ans++;
        l++;
        r--;
      } else {
        r--;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
