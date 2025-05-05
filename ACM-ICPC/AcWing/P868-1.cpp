/**
 * @platform: AcWing
 * @problem: P868-1
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-18
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  function<vector<bool>(int)> get_prime = [&](int maxn) {
    vector<bool> is_prime(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxn / i; i++) {
      if (is_prime[i]) {
        for (int j = i * i; j <= maxn; j += i) {
          is_prime[j] = false;
        }
      }
    }
    return is_prime;
  };
  int ans = 0;
  auto is_prime = get_prime(n);
  for (int i = 1; i <= n; i++) {
    if (is_prime[i])
      ans++;
  }
  cout << ans << '\n';

  return 0;
}
