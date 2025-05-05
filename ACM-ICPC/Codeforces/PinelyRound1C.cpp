/**
 * @platform: Codeforces
 * @problem: PinelyRound#1C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-20
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
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
      cin >> matrix[i];
    }
    vector<set<int>> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i].insert(i + 1);
    }
    vector<bool> vis(n, false);
    for (int j = 0; j < n; j++) {
      bool flag = false;
      for (int i = 0; i < n; i++) {
        if (matrix[i][j] == '1') {
          flag = true;
          break;
        }
      }
      if (!flag) {
        queue<int> q;
        q.push(j);
        while (!q.empty()) {
          int row = q.front();
          q.pop();
          for (int col = 0; col < n; col++) {
            if (matrix[row][col] == '1') {
              for (auto &e : ans[row]) {
                ans[col].insert(e);
                if (!vis[col]) {
                  vis[col] = true;
                  q.push(col);
                }
              }
            }
          }
        }
      }
    }
    for (auto &i : ans) {
      int size = i.size();
      cout << size << " ";
      for (auto &e : i) {
        cout << e << " ";
      }
      cout << '\n';
    }
  }

  return 0;
}
