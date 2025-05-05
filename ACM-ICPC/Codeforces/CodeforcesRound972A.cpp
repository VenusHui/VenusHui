/**
 * @platform: Codeforces
 * @problem: CodeforcesRound972A
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-18
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
  string s = "aeiou";
  while (t--) {
    int n;
    cin >> n;
    int size = n / 5, each = n % 5;
    for (int i = 0; i < 5; i++) {
      int extra = each > i ? 1 : 0;
      string ss(size + extra, s[i]);
      cout << ss;
    }
    cout << '\n';
  }

  return 0;
}
