/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1027A
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
    string s;
    cin >> s;
    int num = stoi(s);
    int fact = sqrt(num);
    if (fact * fact == num) {
      cout << 0 << " " << fact << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}
