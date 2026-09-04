/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1084C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-03-06
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
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
    int ans = 0;
    bool flag = true;
    string cnt = s;
    while (flag) {
      flag = false;
      int size = cnt.size();
      string nxt;
      for (int i = 0; i < size; i++) {
        if (i < size - 1 && cnt[i] == cnt[i + 1]) {
          flag = true;
          i++;
        } else {
          nxt += cnt[i];
        }
      }
      cnt = nxt;
    }
    if (cnt.size() == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
