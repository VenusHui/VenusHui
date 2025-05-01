/**
 * @platform: Codeforce
 * @problem: CodeforcesRound#805D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-10
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
    string w;
    cin >> w;
    int p, size = w.size(), tot = 0;
    cin >> p;
    vector<int> res(26, 0), del(26, 0);
    for (int i = 0; i < size; i++) {
      res[w[i] - 'a']++;
      tot += (w[i] - 'a' + 1);
    }
    char ch = 'z';
    while (tot > p) {
      if (res[ch - 'a'] > 0) {
        res[ch - 'a']--;
        del[ch - 'a']++;
        tot -= (ch - 'a' + 1);
      } else {
        ch--;
      }
    }
    vector<bool> tmp(size, true);
    for (int i = 0; i < size; i++) {
      if (del[w[i] - 'a'] > 0) {
        tmp[i] = false;
        del[w[i] - 'a']--;
      }
    }
    string ans;
    for (int i = 0; i < size; i++) {
      if (tmp[i]) {
        ans += w[i];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
