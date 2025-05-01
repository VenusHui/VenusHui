/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound24C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-26
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]]++;
    }
    if (mp.size() == 1) {
      cout << n / 2 << '\n';
      continue;
    }
    ll ans = 0, num = 0;
    for (auto &i : mp) {
      num += i.second;
      ans = max(ans, num * (n - num));
    }
    cout << ans << '\n';
  }

  return 0;
}
