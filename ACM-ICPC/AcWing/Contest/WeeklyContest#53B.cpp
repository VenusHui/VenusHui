/**
 * @platform: Acwing
 * @problem: WeeklyContest#53B
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
  string s;
  cin >> s;
  ll ans = 0;
  int size = s.size();
  for (int i = 0; i < size; i++) {
    if ((s[i] - '0') % 4 == 0) {
      ans++;
    }
  }
  for (int i = 0; i < size - 1; i++) {
    if (((s[i] - '0') * 10 + s[i + 1] - '0') % 4 == 0) {
      ans += (i + 1);
    }
  }
  cout << ans << '\n';

  return 0;
}
