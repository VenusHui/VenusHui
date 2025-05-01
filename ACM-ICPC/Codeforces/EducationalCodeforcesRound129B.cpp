/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound129B
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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int pos = 0;
    for (int i = 0; i < m; i++) {
      pos = (pos + b[i]) % n;
    }
    cout << a[pos] << '\n';
  }

  return 0;
}
