/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#829D
 * @version: Contest Version (Unsolved)
 * @author: VenusHui
 * @date: 2022-10-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 500000 + 1;
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> res(maxn);
  for (int i = 0; i < n; i++) {
    res[a[i]]++;
  }
  vector<int> pre(maxn);
  for (int i = maxn - 1; i >= 1; i--) {
    pre[i - 1] = pre[i] + res[i];
  }

  return 0;
}
