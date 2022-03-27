#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
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
#define endl '\n';
using namespace std;

// 二分答案

int n;
ll k;
bool check(vector<ll>& res, ll num) {
    ll tmp = k;
    for (int i = 1; i <= n; i++) {
        tmp -= max(num - res[i], 0LL);
        if (tmp < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<ll> res(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> res[i];
    }
    ll l = 0, r = 1e14;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(res, mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << '\n';

    return 0;
}
