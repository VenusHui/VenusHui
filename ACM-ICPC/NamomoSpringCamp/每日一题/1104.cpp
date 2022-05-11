/***********************************
 *  Daimayuan Online Judge
 *  简单差分
 *  Writer: VenusHui    
 *  Version: Contest Version
 *  Date: 2022-05-10
***********************************/
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
#include <functional>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    vector<ll> sub(n);
    sub[0] = res[0];
    for (int i = 1; i < n; i++) {
        sub[i] = res[i] - res[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        sub[l - 1] += x;
        sub[r] -= x;
    }
    vector<ll> pre(n), ans(n);
    partial_sum(sub.begin(), sub.end(), pre.begin());
    partial_sum(pre.begin(), pre.end(), ans.begin());
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        if (l - 2 < 0) {
            cout << ans[r - 1] << '\n';
        }
        else {
            cout << ans[r - 1] - ans[l - 2] << '\n';
        }
    }

    return 0;
}
