/**
 * @platform: AcWing
 * @problem: WeeklyContest#58A
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
  bool ans = false;
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
    if (res[i] == 1) {
      ans = true;
    }
  }
  if (ans) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}
