/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#826A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-11
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
    string a, b;
    cin >> a >> b;
    int ansa = 0, ansb = 0;
    int asize = a.size(), bsize = b.size();
    for (int i = 0; i < asize; i++) {
      if (a[i] == 'L') {
        ansa = ansa * 1 + 1;
      } else if (a[i] == 'X') {
        ansa += 1;
      } else if (a[i] == 'S') {
        ansa = ansa * -1 - 1;
      }
    }
    for (int i = 0; i < bsize; i++) {
      if (b[i] == 'L') {
        ansb = ansb * 1 + 1;
      } else if (b[i] == 'X') {
        ansb += 1;
      } else if (b[i] == 'S') {
        ansb = ansb * -1 - 1;
      }
    }
    if (ansa < ansb) {
      cout << "<" << '\n';
    } else if (ansa == ansb) {
      cout << "=" << '\n';
    } else if (ansa > ansb) {
      cout << ">" << '\n';
    }
  }

  return 0;
}
