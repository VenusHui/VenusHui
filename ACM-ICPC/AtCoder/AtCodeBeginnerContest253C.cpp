/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest253C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-28
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  map<int, int> mp;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      if (mp.find(x) == mp.end()) {
        mp.insert(make_pair(x, 1));
      } else {
        mp.find(x)->second++;
      }
    } else if (t == 2) {
      int x, c;
      cin >> x >> c;
      if (mp.find(x) != mp.end() && mp.find(x)->second > c) {
        mp.find(x)->second -= c;
      } else {
        mp.erase(x);
      }
    } else if (t == 3) {
      auto it = mp.end();
      it--;
      cout << it->first - mp.begin()->first << '\n';
    }
  }

  return 0;
}
