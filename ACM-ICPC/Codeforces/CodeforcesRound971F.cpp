/**
 * @platform: Codeforces
 * @problem: CodeforcesRound971F
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-06
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        vector<ll> pre(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        // x 翻转下的前 p 个数的和
        auto calc = [&] (int x, int p) {
            if (p == 0) return 0LL;
            if (x - 1 + p <= n) {
                return pre[x - 1 + p] - pre[x - 1];
            }
            else {
                return pre[n] - pre[x - 1] + pre[p + x - 1 - n];
            }
        };
        while (q--) {
            ll l, r;
            cin >> l >> r;
            ll lsum = (l - 1) / n * pre[n] + calc((l - 1) / n + 1, (l - 1) % n);
            ll rsum = r / n * pre[n] + calc(r / n + 1, r % n);
            cout << rsum - lsum << '\n';
        }
    }
    
    return 0;
}
