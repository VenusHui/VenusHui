/**
 * @platform: AcWing
 * @problem: P801
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), ans(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i]) {
      a[i] -= (a[i] & -a[i]);
      ans[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';

  return 0;
}
