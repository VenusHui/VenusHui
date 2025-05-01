/**
 * @platform: AcWing
 * @problem: P837
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-20
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<pair<int, int>> disjoint_set;
  function<int(int)> find = [&](int x) {
    if (disjoint_set[x].first != x)
      disjoint_set[x].first = find(disjoint_set[x].first);
    return disjoint_set[x].first;
  };
  function<bool(int, int)> together = [&](int a, int b) {
    return find(a) == find(b);
  };
  function<void(int, int)> set_union = [&](int a, int b) {
    if (together(a, b))
      return;
    disjoint_set[find(b)].second += disjoint_set[find(a)].second;
    disjoint_set[find(a)].first = find(b);
  };
  function<int(int)> set_size = [&](int a) {
    return disjoint_set[find(a)].second;
  };
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    disjoint_set.push_back(make_pair(i, 1));
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "C") {
      int a, b;
      cin >> a >> b;
      set_union(a, b);
    }
    if (oper == "Q1") {
      int a, b;
      cin >> a >> b;
      if (together(a, b))
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    }
    if (oper == "Q2") {
      int a;
      cin >> a;
      cout << set_size(a) << '\n';
    }
  }

  return 0;
}
