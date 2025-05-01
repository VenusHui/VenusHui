/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#788B Dorms War
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-05-19
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
    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;
    vector<bool> flag(26);
    flag['{' - 'a'] = true;
    for (int i = 0; i < k; i++) {
      char ch;
      cin >> ch;
      flag[ch - 'a'] = true;
    }
    int ans = 0;
    vector<int> res;
    res.push_back(0);
    for (int i = 0; i < n; i++) {
      if (flag[s[i] - 'a']) {
        res.push_back(i);
      }
    }
    int size = res.size();
    for (int i = 1; i < size; i++) {
      ans = max(ans, res[i] - res[i - 1]);
    }
    cout << ans << '\n';
  }

  return 0;
}
