/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#793C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-22
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.push_back(1e9 + 1);
    vector<int> res;
    int tmp = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[i + 1]) {
        tmp++;
      } else {
        res.push_back(tmp);
        tmp = 1;
      }
    }
    int size = res.size();
    int single = 0, both = 0;
    for (int i = 0; i < size; i++) {
      if (res[i] == 1) {
        single++;
      } else {
        both++;
      }
    }
    cout << both + (single + 1) / 2 << '\n';
  }

  return 0;
}
