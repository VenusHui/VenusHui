/**
 * @platform: AcWing
 * @problem: P800
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  function<void()> solve1 = [&]() {
    // 二分
    for (int i = 0; i < n; i++) {
      int l = 0, r = m - 1;
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[i] + b[mid] <= x) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (a[i] + b[l] == x) {
        cout << i << " " << l << '\n';
        break;
      }
    }
  };
  function<void()> solve2 = [&]() {
    // 双指针
    int i = 0, j = m - 1;
    for (i; i < n; i++) {
      while (j >= 0 && a[i] + b[j] > x)
        j--;
      if (a[i] + b[j] == x) {
        break;
      }
    }
    cout << i << " " << j << '\n';
  };

  if (rand() % 2 == 0)
    solve1();
  else
    solve2();

  return 0;
}
