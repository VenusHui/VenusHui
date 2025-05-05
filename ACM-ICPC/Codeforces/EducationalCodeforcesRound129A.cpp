/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound129A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-23
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
    int n, m, maxa = 0, maxb = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxa = max(maxa, a[i]);
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      maxb = max(maxb, b[i]);
    }
    if (maxa > maxb) {
      cout << "Alice" << '\n';
      cout << "Alice" << '\n';
    } else if (maxa < maxb) {
      cout << "Bob" << '\n';
      cout << "Bob" << '\n';
    } else {
      cout << "Alice" << '\n';
      cout << "Bob" << '\n';
    }
  }

  return 0;
}
