/**
 * @platform: AcWing
 * @problem: P154
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  deque<int> q;
  for (int i = 0; i < n; i++) {
    if (!q.empty() && q.front() < i - k + 1)
      q.pop_front();
    while (!q.empty() && a[q.back()] >= a[i])
      q.pop_back();
    q.push_back(i);
    if (i >= k - 1)
      cout << a[q.front()] << " ";
  }
  cout << '\n', q.clear();
  for (int i = 0; i < n; i++) {
    if (!q.empty() && q.front() < i - k + 1)
      q.pop_front();
    while (!q.empty() && a[q.back()] <= a[i])
      q.pop_back();
    q.push_back(i);
    if (i >= k - 1)
      cout << a[q.front()] << " ";
  }
  cout << '\n';

  return 0;
}
