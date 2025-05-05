/**
 * @platform: Acwing
 * @problem: WeeklyContest#53A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-28
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll x;
  cin >> x;
  string s;
  while (x) {
    s += char(min(x % 10, 9 - x % 10) + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  if (s[0] == '0') {
    s[0] = '9';
  }
  cout << s << '\n';

  return 0;
}
