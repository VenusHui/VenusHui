/**
 * @platform: AcWing
 * @problem: P827
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
  int idx = 2;
  vector<int> list(2, -1), lptr(2, -1), rptr(2, -1);
  lptr[1] = 0, rptr[0] = 1;
  function<void(int, int)> add = [&](int k, int x) {
    list.push_back(x);
    lptr.push_back(k), rptr.push_back(rptr[k]);
    lptr[rptr[k]] = idx, rptr[k] = idx++;
  };
  function<void(int)> remove = [&](int k) {
    lptr[rptr[k]] = lptr[k], rptr[lptr[k]] = rptr[k];
  };
  int m;
  cin >> m;
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "L") {
      int x;
      cin >> x;
      add(0, x);
    }
    if (oper == "R") {
      int x;
      cin >> x;
      add(lptr[1], x);
    }
    if (oper == "D") {
      int k;
      cin >> k;
      remove(k + 1);
    }
    if (oper == "IL") {
      int k, x;
      cin >> k >> x;
      add(lptr[k + 1], x);
    }
    if (oper == "IR") {
      int k, x;
      cin >> k >> x;
      add(k + 1, x);
    }
  }
  for (int i = rptr[0]; i != 1; i = rptr[i]) {
    cout << list[i] << " ";
  }
  cout << '\n';

  return 0;
}
