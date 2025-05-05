/**
 * @platform: AcWing
 * @problem: P826-2
 * @version: Contest Version
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
  int idx = 1;
  vector<int> list(1, -1), next(1, -1);
  function<void(int, int)> add = [&](int k, int x) {
    list.push_back(x), next.push_back(next[k]), next[k] = idx++;
  };
  function<void(int)> remove = [&](int k) { next[k] = next[next[k]]; };
  int m;
  cin >> m;
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "H") {
      int x;
      cin >> x;
      add(0, x);
    }
    if (oper == "D") {
      int k;
      cin >> k;
      remove(k);
    }
    if (oper == "I") {
      int k, x;
      cin >> k >> x;
      add(k, x);
    }
  }
  for (int i = 0; i != -1; i = next[i]) {
    if (i > 0)
      cout << list[i] << " ";
  }
  cout << '\n';

  return 0;
}
