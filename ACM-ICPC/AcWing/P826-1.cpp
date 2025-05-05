/**
 * @platform: AcWing
 * @problem: P826
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
  int m;
  cin >> m;
  int head = -1, idx = 0;
  vector<int> list, next;
  function<void(int, int)> add = [&](int k, int x) {
    if (k == -1)
      list.push_back(x), next.push_back(head), head = idx++;
    else
      list.push_back(x), next.push_back(next[k]), next[k] = idx++;
  };
  function<void(int)> remove = [&](int k) {
    if (k == -1)
      head = next[head];
    else
      next[k] = next[next[k]];
  };
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "H") {
      int x;
      cin >> x;
      add(-1, x);
    }
    if (oper == "D") {
      int k;
      cin >> k;
      remove(k - 1);
    }
    if (oper == "I") {
      int k, x;
      cin >> k >> x;
      add(k - 1, x);
    }
  }
  for (int i = head; i != -1; i = next[i]) {
    cout << list[i] << " ";
  }
  cout << '\n';

  return 0;
}
