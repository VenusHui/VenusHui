/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1074D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-18
 */
#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> ac = a;
    vector<int> v(n, -1);
    int last_reset = -1;
    for (int i = 0; i < m; i++) {
      int b, c;
      cin >> b >> c;
      b--;
      if (v[b] < last_reset) {
        ac[b] = a[b];
      }
      ac[b] += c;
      if (ac[b] > h) {
        last_reset = i;
        ac[b] = a[b];
      }
      v[b] = i;
    }
    for (int i = 0; i < n; i++) {
      if (v[i] < last_reset)
        cout << a[i] << " ";
      else
        cout << ac[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
