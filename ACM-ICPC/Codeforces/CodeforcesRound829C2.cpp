/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#829C2
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-23
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
    vector<int> a(n);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tmp += a[i];
    }
    if (tmp % 2 != 0) {
      cout << "-1" << '\n';
      continue;
    }
    vector<bool> vis(n, false);
    vector<pair<int, int>> ans;
    int index = 1;
    if (tmp < 0) {
      while (tmp < 0) {
        for (int i = index; i < n; i++) {
          if (!vis[i - 1] && !vis[i] && a[i] == -1) {
            vis[i - 1] = true;
            vis[i] = true;
            ans.push_back(make_pair(i, i + 1));
            index = i + 1;
            break;
          }
        }
        tmp += 2;
      }
    } else {
      while (tmp > 0) {
        for (int i = index; i < n; i++) {
          if (!vis[i - 1] && !vis[i] && a[i] == 1) {
            vis[i - 1] = true;
            vis[i] = true;
            ans.push_back(make_pair(i, i + 1));
            index = i + 1;
            break;
          }
        }
        tmp -= 2;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ans.push_back(make_pair(i + 1, i + 1));
      }
    }
    sort(ans.begin(), ans.end());
    int size = ans.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++) {
      cout << ans[i].first << " " << ans[i].second << '\n';
    }
  }

  return 0;
}
