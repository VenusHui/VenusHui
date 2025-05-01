/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#817A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-12
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
    string s;
    cin >> s;
    if (n != 5) {
      cout << "NO" << '\n';
      continue;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    bool flag = true;
    if (mp.size() != 5 || mp['T'] != 1 || mp['i'] != 1 || mp['m'] != 1 ||
        mp['u'] != 1 || mp['r'] != 1) {
      flag = false;
    }
    if (flag) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
