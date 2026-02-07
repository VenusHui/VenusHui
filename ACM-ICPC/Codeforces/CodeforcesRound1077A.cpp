/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1077A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-30
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
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      ans.push_back(n - i + 1);
      ans.push_back(i);
    }
    vector<int> f(ans.begin(), ans.begin() + n);
    reverse(f.begin(), f.end());
    for (int i = 0; i < n; i++) {
      cout << f[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
