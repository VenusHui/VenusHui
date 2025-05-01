/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound172A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-02
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end(), [&](int a, int b) { return a > b; });
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (k >= a[i]) {
        k = k - a[i];
      } else {
        ans += k;
        k -= k;
        break;
      }
    }

    cout << ans + k << '\n';
  }

  return 0;
}
