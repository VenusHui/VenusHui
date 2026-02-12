/**
 * @platform: Codeforecs
 * @problem: CodeforcesRound1076A
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
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    bool ans = true;
    if (s < sum || (sum - s) % x) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}
