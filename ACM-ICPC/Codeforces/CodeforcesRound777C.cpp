#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
typedef long long ll;
using namespace std;

// Codeforces Round #777 (Div. 2) C. Madoka and Childish Pranks

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
      cin >> mp[i];

    if (mp[0][0] == '1') {
      cout << "-1" << '\n';
      continue;
    }
    int ans = 0;
    vector<pair<pair<int, int>, pair<int, int>>> sol;
    // 处理第二行到最后一行
    for (int i = n - 1; i >= 1; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (mp[i][j] == '1') {
          ans++;
          sol.push_back(
              make_pair(make_pair(i, j + 1), make_pair(i + 1, j + 1)));
        }
      }
    }
    // 处理第一行
    for (int i = m - 1; i >= 0; i--) {
      if (mp[0][i] == '1') {
        ans++;
        sol.push_back(make_pair(make_pair(1, i), make_pair(1, i + 1)));
      }
    }

    // 输出答案
    cout << ans << '\n';
    if (ans == 0)
      continue;
    for (int i = 0; i < ans; i++)
      cout << sol[i].first.first << " " << sol[i].first.second << " "
           << sol[i].second.first << " " << sol[i].second.second << '\n';
  }

  return 0;
}