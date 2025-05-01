/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#805B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-10
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
    int size = s.size(), ans = 0;
    set<char> st;
    for (int i = 0; i < size; i++) {
      if (st.find(s[i]) == st.end()) {
        if (st.size() < 3) {
          st.insert(s[i]);
        } else {
          ans++;
          st.clear();
          st.insert(s[i]);
        }
      }
    }
    if (st.size() != 0) {
      ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}
