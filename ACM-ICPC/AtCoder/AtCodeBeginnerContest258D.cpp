/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest258D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  ll ans = a[0] + 1LL * b[0] * x;
  ll tmp = 1e9 + 1;
  ll tot = 0;
  for (int i = 0; i < n; i++) {
    tmp = min(tmp, b[i]);
    ans = min(ans, tot + a[i] + b[i] + (x - i - 1) * tmp);
    tot += a[i] + b[i];
  }
  cout << ans << '\n';

  return 0;
}
