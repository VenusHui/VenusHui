/**
 * @platform: AcWing
 * @problem: WeeklyContest#58B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1, tmp = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] <= 2 * a[i]) {
      tmp++;
    } else {
      ans = max(ans, tmp);
      tmp = 1;
    }
  }
  cout << max(ans, tmp) << '\n';

  return 0;
}
