/**
 * @platform: CodeforcesRound
 * @problem: CodeforcesRound1073A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-22
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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = make_pair(a[i], i % 2);
    }
    sort(v.begin(), v.end());
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
      if (v[i].second == v[i + 1].second) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
