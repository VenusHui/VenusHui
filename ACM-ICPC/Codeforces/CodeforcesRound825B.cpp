/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#825B
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-10-10
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    b[0] = a[0];
    b[n] = a[n - 1];
    for (int i = 1; i < n; i++) {
      b[i] = lcm(a[i - 1], a[i]);
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != gcd(b[i], b[i + 1])) {
        flag = false;
      }
    }
    if (flag) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
