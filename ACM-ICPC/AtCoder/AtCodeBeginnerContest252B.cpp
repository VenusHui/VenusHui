/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest252B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-21
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> res(n), tmp(n), b(k);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
    tmp[i] = res[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  sort(tmp.begin(), tmp.end(), [](int &a, int &b) { return a > b; });
  for (int i = 0; i < n; i++) {
    if (res[i] == tmp[0]) {
      for (int j = 0; j < k; j++) {
        if (i + 1 == b[j]) {
          cout << "Yes" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "No" << '\n';

  return 0;
}
