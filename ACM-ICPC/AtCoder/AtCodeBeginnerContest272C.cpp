/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest272C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-08
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 2 && (a[0] + a[1]) % 2 != 0) {
    cout << "-1" << '\n';
    return 0;
  }
  int em1 = 0, em2 = 0, om1 = 0, om2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      if (a[i] > em1) {
        em2 = em1;
        em1 = a[i];
      } else if (a[i] > em2) {
        em2 = a[i];
      }
    } else {
      if (a[i] > om1) {
        om2 = om1;
        om1 = a[i];
      } else if (a[i] > om2) {
        om2 = a[i];
      }
    }
  }
  ll ans = max(em1 + em2, om1 + om2);
  cout << ans << '\n';

  return 0;
}
