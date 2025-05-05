/**
 * @platform: AcWing
 * @problem: P829-2
 * @version: Contest Version
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
  int head = 0, tail = -1;
  vector<int> q;
  function<void(int)> push = [&](int x) { q.push_back(x), tail++; };
  function<void()> pop = [&]() { head++; };
  function<bool()> empty = [&]() { return tail - head < 0; };
  function<int()> query = [&]() { return q[head]; };
  int m;
  cin >> m;
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "push") {
      int x;
      cin >> x;
      push(x);
    }
    if (oper == "pop") {
      pop();
    }
    if (oper == "empty") {
      if (empty())
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
    if (oper == "query") {
      cout << query() << '\n';
    }
  }

  return 0;
}
