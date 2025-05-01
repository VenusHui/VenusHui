/**
 * @platform: AcWing
 * @problem: P831
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-17
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  string p, s;
  cin >> n >> p >> m >> s;
  vector<int> next(n);
  for (int i = 1, j = 0; i < n; i++) {
    while (j && p[i] != p[j])
      j = next[j - 1];
    if (p[i] == p[j])
      j++;
    next[i] = j;
  }
  for (int i = 0, j = 0; i < m; i++) {
    while (j && s[i] != p[j])
      j = next[j - 1];
    if (s[i] == p[j])
      j++;
    if (j == n) {
      cout << i - j + 1 << " ";
    }
  }
  cout << '\n';

  return 0;
}
