/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1027B
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-05-30
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int num = 0;
    for (auto &e : s) {
      if (e == '0')
        num++;
    }
    if (num >= n / 2 - k && n - num >= n / 2 - k &&
        (num - n / 2 + k) % 2 == 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
