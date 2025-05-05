/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest272B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-08
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<set<int>> res(n + 1);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int> tmp(k);
    for (int j = 0; j < k; j++) {
      cin >> tmp[j];
    }
    for (int j = 0; j < k; j++) {
      for (int t = 0; t < k; t++) {
        res[tmp[j]].insert(tmp[t]);
      }
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (res[i].size() < n) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}
