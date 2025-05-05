/**
 * @platform: AcWing
 * @problem: P846
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-15
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
  vector<int> disjoint_set(n);
  function<int(int)> find = [&](int x) {
    if (disjoint_set[x] != x)
      disjoint_set[x] = find(disjoint_set[x]);
    return disjoint_set[x];
  };
  function<void(int, int)> set_union = [&](int a, int b) {
    disjoint_set[find(a)] = find(b);
  };
  function<bool(int, int)> is_union = [&](int a, int b) {
    return find(a) == find(b);
  };
  for (int i = 0; i < n; i++)
    disjoint_set[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    set_union(a, b);
  }

  return 0;
}
