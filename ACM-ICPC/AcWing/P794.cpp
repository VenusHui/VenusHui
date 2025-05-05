/**
 * @platform: AcWing
 * @problem: P794
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<string, int> div(string s, int num) {
  pair<string, int> ans = make_pair("", 0);
  for (int i = 0; i < s.size(); i++) {
    ans.second = ans.second * 10 + s[i] - '0';
    ans.first += ans.second / num + '0';
    ans.second %= num;
  }
  while (ans.first.size() > 1 && ans.first.front() == '0')
    ans.first.erase(ans.first.begin());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  int num;
  cin >> s >> num;
  pair<string, int> ans = div(s, num);
  cout << ans.first << '\n' << ans.second << '\n';

  return 0;
}
