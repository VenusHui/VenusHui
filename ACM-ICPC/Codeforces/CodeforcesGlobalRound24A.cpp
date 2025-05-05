/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound24A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-26
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << "1 " << n << '\n';
  }

  return 0;
}
