#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
using namespace std;

// 数位计算

ll calc(ll num) {
    ll ans = 1;
    for (ll i = 0; i < num; i++) {
        ans *= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const ll mod = 998244353;
    ll n, ans = 0;
    cin >> n;
    ll pos = 0, tmp = n;
    ll first = 1;
    ll last = 9 * calc(pos);
    while (tmp / 10) {
        first = 1;
        last = 9 * calc(pos);
        ll left = (first + last) % mod;
        ll right = last % mod;
        ans += left * right / 2 % mod;
        ans %= mod;
        tmp /= 10;
        pos++;
    }
    last = n - calc(pos) + 1;
    ll left = (first + last) % mod;
    ll right = last % mod;
    ans += left * right / 2 % mod;
    ans %= mod;
    cout << ans << '\n';

    return 0;
}
