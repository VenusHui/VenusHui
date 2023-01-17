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
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

// 字节跳动2019春招研发编程题部分 B

inline ll calc(vector<ll>& res, int l, int r, ll d) {
    int s = l;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (res[m] - res[s] <= d) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l - s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int mod = 99997867;
    ll n, d;
    cin >> n >> d;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll num = calc(res, i, n, d);
        ans = (ans + num * (num - 1) / 2 % mod) % mod;
    }
    cout << ans % mod << '\n';

    return 0;
}
