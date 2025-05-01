/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest253D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-28
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n, a, b;
  cin >> n >> a >> b;
  ll num = __gcd(a, b);
  ll as = a, ae = n / a * a, bs = b, be = n / b * b, cs = a * b / num,
     ce = n / (a * b / num) * a * b / num;
  ll sub1 = (as + ae) * (n / a) / 2, sub2 = (bs + be) * (n / b) / 2;
  ll sum = (cs + ce) * (n / (a * b / num)) / 2;
  cout << (1 + n) * n / 2 - sub1 - sub2 + sum << '\n';

  return 0;
}
