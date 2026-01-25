/**
 * @platform: CodeforcesRound
 * @problem: CodeforcesRound1076E
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-25
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(a[i]);
    }
    vector<int> nums(s.begin(), s.end());
    vector<int> dist(n + 1, -1);
    queue<int> q;
    for (auto &e : nums) {
      dist[e] = 1;
      q.push(e);
    }
    while (!q.empty()) {
      int cnt = q.front();
      q.pop();
      for (auto &e : nums) {
        ll next = 1LL * cnt * e;
        if (next > n)
          break;
        if (dist[next] == -1) {
          dist[next] = dist[cnt] + 1;
          q.push(static_cast<int>(next));
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << dist[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
