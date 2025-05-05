/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#790 H2. Maximum Crossings (Hard Version)
 * @version: Tutorial
 * @author: VenusHui
 * @date: 2022-05-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

inline int ask(vector<int> &tree, int x) {
  int ans = 0;
  for (; x; x -= x & -x) {
    ans += tree[x];
  }
  return ans;
}

inline void add(vector<int> &tree, int x, int y) {
  for (; x <= n; x += x & -x) {
    tree[x] += y;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> res(n + 1), tree(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> res[i];
    }
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
      ans += ask(tree, res[i]);
      add(tree, res[i], 1);
    }
    cout << ans << '\n';
  }

  return 0;
}
