/**
 * @platform: AcWing
 * @problem: P792
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string sub(string s1, string s2) {
  bool flag = s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2;
  if (flag)
    swap(s1, s2);
  string ans;
  int t = 0, i = s1.size() - 1, j = s2.size() - 1;
  while (i >= 0) {
    t = s1[i] - '0' - t;
    t -= j >= 0 ? s2[j] - '0' : 0;
    ans += (t + 10) % 10 + '0';
    t = t < 0 ? 1 : 0;
    i--, j--;
  }
  while (ans.size() > 1 && ans.back() == '0')
    ans.pop_back();
  if (flag)
    ans += '-';
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s1, s2;
  cin >> s1 >> s2;
  cout << sub(s1, s2) << '\n';

  return 0;
}
