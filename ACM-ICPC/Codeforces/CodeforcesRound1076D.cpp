/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1076D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-25
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll x = a[i];
      ll cnt = i + 1;
      int lo = 0, hi = n;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (prefix[mid] <= cnt) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }

      ans = max(ans, x * lo);
    }
    cout << ans << "\n";
  }
  return 0;
}
