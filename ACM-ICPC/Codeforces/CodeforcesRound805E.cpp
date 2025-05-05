/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#805E
 * @version: Contest Version - UnSolved (WA)
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
    int n;
    cin >> n;
    bool ans = true;
    vector<pair<int, int>> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i].first >> res[i].second;
      if (res[i].first == res[i].second) {
        ans = false;
      }
    }
    set<int> st1, st2;
    vector<bool> tmp(n, true);
    for (int i = 0; i < n; i++) {
      if (st1.find(res[i].first) == st1.end() &&
          st1.find(res[i].second) == st1.end()) {
        st1.insert(res[i].first);
        st1.insert(res[i].second);
        tmp[i] = false;
      }
    }
    for (int i = 0; i < n; i++) {
      if (tmp[i]) {
        st2.insert(res[i].first);
        st2.insert(res[i].second);
      }
    }
    if (st1 != st2) {
      ans = false;
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
