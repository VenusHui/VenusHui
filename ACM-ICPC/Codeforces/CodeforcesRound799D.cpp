/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#799D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-14
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 1440;
  int t;
  cin >> t;
  while (t--) {
    string s;
    int x;
    cin >> s >> x;
    function<string(string)> calc = [&](string time) {
      int h = (time[0] - '0') * 10 + (time[1] - '0');
      int m = (time[3] - '0') * 10 + (time[4] - '0');
      int now = (h * 60 + m + x) % maxn;
      h = now / 60;
      m = now % 60;
      string res;
      res += '0' + h / 10;
      res += '0' + h % 10;
      res += ':';
      res += '0' + m / 10;
      res += '0' + m % 10;
      return res;
    };
    set<string> st;
    for (int i = 0; i < maxn; i++) {
      string nxt = calc(s);
      string tmp = nxt;
      reverse(tmp.begin(), tmp.end());
      if (nxt == tmp) {
        st.insert(nxt);
      }
      s = nxt;
    }
    int ans = st.size();
    cout << ans << '\n';
  }

  return 0;
}
