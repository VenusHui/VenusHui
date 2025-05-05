/**
 * @platform: AcWing
 * @problem: P830
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-14
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
  stack<int> stk;
  vector<int> a(n), ans(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && stk.top() >= a[i])
      stk.pop();
    ans[i] = stk.empty() ? -1 : stk.top();
    stk.push(a[i]);
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << '\n';

  return 0;
}
