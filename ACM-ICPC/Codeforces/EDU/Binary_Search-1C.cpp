/**
 * @platform: Codeforces
 * @problem: Binary_Search-1C
 * @version: EDU
 * @author: VenusHui
 * @date: 2022-05-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> res(n);
  for (int i = 1; i <= n; i++) {
    cin >> res[i];
  }
  for (int i = 0; i < k; i++) {
    int num;
    cin >> num;
    if (num > res[n]) {
      cout << n + 1 << '\n';
      continue;
    }
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) >> 1;
      if (res[m] < num) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    cout << l << '\n';
  }

  return 0;
}
