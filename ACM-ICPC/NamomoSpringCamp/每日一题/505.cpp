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

// 新国王游戏

int n;
vector<pair<ll, ll>> p;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return b.second + a.second * b.first < a.second + b.second * a.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const ll mod = 1000000007;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end(), cmp);
    ll sum = 1, res = p[0].second;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            res = (res + (sum * p[i].second) % mod) % mod;
        }
        sum = (sum * p[i].first) % mod;
    }
    cout << res % mod << '\n';

    return 0;
}
