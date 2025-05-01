/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest252C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-21
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
  vector<string> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  int ans = 1e9 + 1;
  for (int s = 0; s <= 9; s++) {
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 9; j++) {
        if (res[i][j] - '0' == s) {
          tmp.push_back(j);
        }
      }
    }
    int fac = 0;
    sort(tmp.begin(), tmp.end());
    tmp.push_back(1e9 + 1);
    vector<pair<int, int>> x;
    for (int i = 0; i < n; i++) {
      if (tmp[i] == tmp[i + 1]) {
        fac++;
      } else {
        x.push_back(make_pair(fac, tmp[i]));
        fac = 0;
      }
    }
    sort(x.begin(), x.end());
    int size = x.size();
    ans = min(ans, x[size - 1].first * 10 + x[size - 1].second);
  }
  cout << ans << '\n';

  return 0;
}
