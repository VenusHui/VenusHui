/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1084B
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        flag = false;
    }
    if (flag) {
      cout << n << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
  return 0;
}
