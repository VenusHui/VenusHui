/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#817C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 3;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> a, b, c;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      a.insert(make_pair(s, 1));
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      b.insert(make_pair(s, 1));
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      c.insert(make_pair(s, 1));
    }
    int as = 0, bs = 0, cs = 0;
    for (auto e : a) {
      if (b.find(e.first) == b.end() && c.find(e.first) == c.end()) {
        as += 3;
      } else if (b.find(e.first) == b.end() && c.find(e.first) != c.end()) {
        as++;
      } else if (b.find(e.first) != b.end() && c.find(e.first) == c.end()) {
        as++;
      }
    }
    for (auto e : b) {
      if (a.find(e.first) == a.end() && c.find(e.first) == c.end()) {
        bs += 3;
      } else if (a.find(e.first) == a.end() && c.find(e.first) != c.end()) {
        bs++;
      } else if (a.find(e.first) != a.end() && c.find(e.first) == c.end()) {
        bs++;
      }
    }
    for (auto e : c) {
      if (b.find(e.first) == b.end() && a.find(e.first) == a.end()) {
        cs += 3;
      } else if (b.find(e.first) == b.end() && a.find(e.first) != a.end()) {
        cs++;
      } else if (b.find(e.first) != b.end() && a.find(e.first) == a.end()) {
        cs++;
      }
    }
    cout << as << " " << bs << " " << cs << '\n';
  }

  return 0;
}
