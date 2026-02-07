/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1077C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-02-07
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    if (sorted_a == a) {
      cout << "-1" << '\n';
      continue;
    }
    int ans = sorted_a[n - 1] - sorted_a[0];
    for (int i = 0; i < n; i++) {
      if (sorted_a[i] != a[i]) {
        ans = min(ans, max(a[i] - sorted_a[0], sorted_a[n - 1] - a[i]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
