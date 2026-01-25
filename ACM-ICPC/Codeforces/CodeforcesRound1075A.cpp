/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1075A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-23
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
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    int r1 = min(h, l), r2 = max(h, l);
    int ans = 0, num = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > r1 && a[i] <= r2) {
        ans++;
      }
      if (a[i] <= r2)
        num++;
    }
    if (ans * 2 > num) {
      cout << (num - ans) << '\n';
    } else {
      cout << num / 2 << '\n';
    }
  }
  return 0;
}
