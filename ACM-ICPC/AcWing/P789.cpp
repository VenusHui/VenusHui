/**
 * @platform: AcWing
 * @problem: P789
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int k;
    cin >> k;
    pair<int, int> ans = make_pair(-1, -1);
    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + r + 1 >> 1;
      if (a[m] <= k) { // 有等号就取到小于等于 k 的最大的
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (a[l] == k) {
      ans.second = l;
    }
    l = 0, r = n - 1;
    while (l < r) {
      int m = l + r >> 1;
      if (a[m] < k) { // 没等号就取到小于 k 的最大的
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (a[l] == k) {
      ans.first = l;
    }
    cout << ans.first << " " << ans.second << '\n';
  }

  return 0;
}
