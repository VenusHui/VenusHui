/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#798A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    priority_queue<char, vector<char>, greater<char>> pqa, pqb;
    for (int i = 0; i < n; i++) {
      pqa.push(a[i]);
    }
    for (int i = 0; i < m; i++) {
      pqb.push(b[i]);
    }
    string c;
    int anum = 0, bnum = 0;
    int flag = 0;
    while (true) {
      if (pqa.empty() || pqb.empty()) {
        break;
      }
      if (flag == 1) {
        flag = 0;
        bnum++;
        anum = 0;
        char tmp = pqb.top();
        pqb.pop();
        c += tmp;
        if (bnum == k) {
          flag = 2;
        }
        continue;
      } else if (flag == 2) {
        flag = 0;
        anum++;
        bnum = 0;
        char tmp = pqa.top();
        pqa.pop();
        c += tmp;
        if (anum == k) {
          flag = 1;
        }
        continue;
      }
      if (pqa.top() <= pqb.top()) {
        anum++;
        bnum = 0;
        char tmp = pqa.top();
        pqa.pop();
        c += tmp;
        if (anum == k) {
          flag = 1;
        }
      } else {
        bnum++;
        anum = 0;
        char tmp = pqb.top();
        pqb.pop();
        c += tmp;
        if (bnum == k) {
          flag = 2;
        }
      }
    }
    cout << c << '\n';
  }

  return 0;
}
