/**
 * @platform: AcWing
 * @problem: P828-1
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
  stack<int> stk;
  int m;
  cin >> m;
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "push") {
      int x;
      cin >> x;
      stk.push(x);
    }
    if (oper == "pop") {
      stk.pop();
    }
    if (oper == "empty") {
      if (stk.empty())
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
    if (oper == "query") {
      cout << stk.top() << '\n';
    }
  }

  return 0;
}
