/**
 * @platform: Acwing
 * @problem: P786
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-09
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  function<void(int, int)> quick_sort = [&](int l, int r) {
    if (l == r) {
      return;
    }
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
      do {
        i++;
      } while (a[i] < x);
      do {
        j--;
      } while (a[j] > x);
      if (i < j) {
        swap(a[i], a[j]);
      }
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
  };
  quick_sort(0, n - 1);
  cout << a[k - 1] << '\n';

  return 0;
}
