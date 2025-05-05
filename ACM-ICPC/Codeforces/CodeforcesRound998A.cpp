/**
 * @platform: Codeforces
 * @problem: CodeforcesRound998A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-19
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
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    a[2] = a[0] + a[1];
    int tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < 3; i++) {
      if (a[i] + a[i + 1] == a[i + 2])
        tmp1++;
    }
    a[2] = a[3] - a[1];
    for (int i = 0; i < 3; i++) {
      if (a[i] + a[i + 1] == a[i + 2])
        tmp2++;
    }
    cout << max(tmp1, tmp2) << '\n';
  }

  return 0;
}
