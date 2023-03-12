/**
 * @platform: AcWing 蓝桥杯集训-每日一题
 * @problem: P3956 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-02-15
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
    vector<int> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (pre[m] - pre[i] <= pre[n] - pre[m]) l = m; 
            else r = m - 1;
        }
        if (pre[l] - pre[i] == pre[i] - pre[0]) ans++;
    }
    cout << ans << '\n';

    return 0;
}
