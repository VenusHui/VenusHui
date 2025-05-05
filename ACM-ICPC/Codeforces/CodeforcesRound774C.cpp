#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
typedef long long ll;
using namespace std;

// Codeforces Round #774 (Div. 2) C. Factorials and Powers of Two

const ll maxNum = 1e12 + 1;

int get_first_bit(long long n) { return 63 - __builtin_clzll(n); }

int get_bit_count(long long n) { return __builtin_popcountll(n); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> fac;
  ll tmp = 6, num = 4;
  while (tmp < maxNum) {
    fac.push_back(tmp);
    tmp *= num;
    num++;
  }
  vector<pair<ll, ll>> sum(1 << fac.size());
  for (int i = 1; i < 1 << fac.size(); i++) {
    int first_bit = get_first_bit(i);
    sum[i].first = sum[i ^ (1 << first_bit)].first + fac[first_bit];
    sum[i].second = get_bit_count(i);
  }
  int t, size = sum.size();
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = get_bit_count(n);
    for (int i = 0; i < size; i++) {
      if (sum[i].first <= n) {
        ans = min(ans, sum[i].second + get_bit_count(n - sum[i].first));
      }
    }
    cout << ans << '\n';
  }

  return 0;
}