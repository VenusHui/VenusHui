/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#834D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 10;
  vector<vector<int>> res(maxn + 1);
  res[2] = {5};
  res[4] = {5};
  res[5] = {2, 4, 6, 8};
  res[6] = {5};
  res[8] = {5};
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll tmp = n, lastn = 0, lastm = 0;
    while (tmp) {
      if (tmp % 10 == 0) {
        tmp /= 10;
      } else {
        lastn = tmp % 10;
        break;
      }
    }
    tmp = m;
    pair<ll, ll> ans = make_pair(0, 0);
    while (tmp) {
      if (tmp % 10 == 0) {
        tmp /= 10;
      } else {
        lastm = tmp % 10;
      }
    }
  }

  return 0;
}
