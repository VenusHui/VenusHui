/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1084A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-03-05
 */
#include <algorithm>
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
    int maxn = *max_element(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == maxn)
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
