/**
 * @platform: AcWing
 * @problem: P795
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i - 1];
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << '\n';
  }

  return 0;
}
