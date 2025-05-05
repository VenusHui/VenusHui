/**
 * @platform: AcWing 蓝桥杯集训-每日一题
 * @problem: P3729
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-02-15
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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> pre(n + 1);
    function<void(int, int, int)> insert = [&](int l, int r, int v) {
      pre[l] += v, pre[r + 1] -= v;
    };
    for (int i = 0; i < n; i++) {
      if (a[i])
        insert(i - a[i] + 1 >= 0 ? i - a[i] + 1 : 0, i, 1);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
      ans[i] = ans[i - 1] + pre[i - 1];
      if (ans[i] > 0)
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << '\n';
  }

  return 0;
}
