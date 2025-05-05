/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#793B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-22
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (i != p[i]) {
        res.push_back(i);
      }
    }
    int size = res.size();
    if (size == 0) {
      cout << size << '\n';
      continue;
    }
    int ans = p[res[0]] & p[res[1]];
    for (auto &it : res) {
      ans &= p[it];
    }
    cout << ans << '\n';
  }

  return 0;
}
