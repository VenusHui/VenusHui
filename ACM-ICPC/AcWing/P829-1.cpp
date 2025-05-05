/**
 * @platform: AcWing
 * @problem: P829-1
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
  queue<int> q;
  int m;
  cin >> m;
  while (m--) {
    string oper;
    cin >> oper;
    if (oper == "push") {
      int x;
      cin >> x;
      q.push(x);
    }
    if (oper == "pop") {
      q.pop();
    }
    if (oper == "empty") {
      if (q.empty())
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
    if (oper == "query") {
      cout << q.front() << '\n';
    }
  }

  return 0;
}
