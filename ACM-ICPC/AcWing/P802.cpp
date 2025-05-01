/**
 * @platform: AcWing
 * @problem: P802
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> alls;
  vector<pair<int, int>> add(n), query(m);
  for (int i = 0; i < n; i++) {
    cin >> add[i].first >> add[i].second;
    alls.push_back(add[i].first);
  }
  for (int i = 0; i < m; i++) {
    cin >> query[i].first >> query[i].second;
    alls.push_back(query[i].first);
    alls.push_back(query[i].second);
  }
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  int size = alls.size();
  function<int(int)> find = [&](int x) {
    int l = 0, r = size - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (alls[mid] < x) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l + 1;
  };
  vector<int> nums(size + 1, 0), pre(size + 1, 0);
  for (auto &e : add) {
    nums[find(e.first)] += e.second;
  }
  for (int i = 1; i <= size; i++) {
    pre[i] = pre[i - 1] + nums[i];
  }
  for (auto &e : query) {
    cout << pre[find(e.second)] - pre[find(e.first) - 1] << '\n';
  }

  return 0;
}
