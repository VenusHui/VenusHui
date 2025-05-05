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
#include <vector>
typedef long long ll;
using namespace std;

// Codeforces Round #779 (Div. 2) B - Marin and Anti-coprime Permutation

const ll mod = 998244353;

inline ll calc(int num) {
  ll ans = 1;
  while (num) {
    ans = (ans * num) % mod;
    num--;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l, r;
    ll tmp = 0;
    if (n % 2 == 0) {
      l = n / 2;
      r = n / 2;
      tmp = (calc(l) * calc(r)) % mod;
    } else {
      l = n / 2 + 1;
      r = n / 2;
    }
    cout << tmp << '\n';
  }

  return 0;
}
