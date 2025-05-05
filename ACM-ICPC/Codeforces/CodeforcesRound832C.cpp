/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#832C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-04
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
    int n;
    cin >> n;
    bool ans = true;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (a[i] < a[0]) {
        ans = false;
      }
    }
    if (!ans) {
      cout << "Alice" << '\n';
    } else {
      cout << "Bob" << '\n';
    }
  }

  return 0;
}
