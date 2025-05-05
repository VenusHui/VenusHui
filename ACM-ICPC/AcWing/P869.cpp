/**
 * @platform: AcWing
 * @problem: P869
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  function<vector<int>(int)> get_fact = [&](int num) {
    vector<int> res;
    for (int i = 1; i <= num / i; i++) {
      if (num % i == 0) {
        res.push_back(i);
        if (i != num / i)
          res.push_back(num / i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  };
  int t;
  cin >> t;
  while (t--) {
    int num;
    cin >> num;
    vector<int> ans = get_fact(num);
    for (auto &e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }

  return 0;
}
