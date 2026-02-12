/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1075C1
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-23
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
    cout << (n - (n & 1));
    for (int i = 2; i <= n - 1; i++) {
      cout << " " << (i ^ 1);
    }
    cout << " " << 1 << '\n';
  }
  return 0;
}
