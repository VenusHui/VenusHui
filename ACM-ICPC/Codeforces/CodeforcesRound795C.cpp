/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#795C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-14
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    int ones = 0, pfirst = n, plast = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ones++;
        pfirst = min(pfirst, i);
        plast = max(plast, i);
      }
    }
    if (ones == 0) {
      ans = 0;
    } else if (ones == 1) {
      if (k >= n - plast - 1) {
        ans = 1;
      } else if (k >= pfirst) {
        ans = 10;
      } else {
        ans = 11;
      }
    } else {
      ans = 11 * ones;
      if (k >= n - plast - 1 + pfirst) {
        ans -= 11;
      } else if (k >= n - plast - 1) {
        ans -= 10;
      } else if (k >= pfirst) {
        ans -= 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
