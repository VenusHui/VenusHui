/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound128 C. Binary String
 * @version: Tutorial
 * @author: VenusHui
 * @date: 2022-05-19
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
    string s;
    cin >> s;
    int size = s.size(), znum = 0, onum = 0;
    for (int i = 0; i < size; i++) {
      if (s[i] == '1') {
        onum++;
      }
    }
    int ans = onum;
    int l = 0, r = 0;
    while (l < size) {
      while (r < size && znum != onum) {
        if (s[r] == '1') {
          onum--;
        } else {
          znum++;
        }
        r++;
      }
      ans = min(ans, max(znum, onum));
      if (s[l] == '1') {
        onum++;
      } else {
        znum--;
      }
      l++;
    }
    cout << ans << '\n';
  }

  return 0;
}
