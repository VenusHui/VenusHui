/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827E 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
 */
#include <bits/stdc++.h>
typedef long long ll;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> pre(n), res(n + 1);
        partial_sum(a.begin(), a.end(), pre.begin());
        pre.insert(pre.begin(), 0);
        for (int i = 1; i <= n; i++) {
            res[i] = max(res[i - 1], a[i - 1]);
        }
        while (q--) {
            ll k;
            cin >> k;
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (res[mid] <= k) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            cout << pre[l] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
