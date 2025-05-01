/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#832A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-04
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
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i];
    }
    cout << abs(ans) << '\n';
  }

  return 0;
}
