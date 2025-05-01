/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest258C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-02
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
  string s;
  cin >> s;
  int end = n - 1;
  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      end = (end - x + n) % n;
    } else {
      int p = (end + x) % n;
      cout << s[p] << '\n';
    }
  }

  return 0;
}
