/**
 * @platform: CodeforcesRound
 * @problem: CodeforcesRound1076C
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    int maxa = -0x3f3f3f3f;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      ans[i] = max(a[i], b[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      maxa = max(maxa, ans[i]);
      ans[i] = max(ans[i], maxa);
    }
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + ans[i];
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      cout << pre[r] - pre[l - 1] << " ";
    }
    cout << '\n';
  }
  return 0;
}
