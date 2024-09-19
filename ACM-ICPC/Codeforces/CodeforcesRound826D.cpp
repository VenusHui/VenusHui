/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#826D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-11
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
        int m;
        cin >> m;
        vector<ll> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        vector<ll> pre(m);
        partial_sum(p.begin(), p.end(), pre.begin());
        pre.insert(pre.begin(), 0LL);
        int ans = 0;
        function<void(int, int)> calc = [&] (int l, int r) {
            if (l == r) {
                return;
            }
            int mid = (l + r) / 2;
            calc(l, mid);
            calc(mid + 1, r);
            if (pre[mid + 1] - pre[l] > pre[r + 1] - pre[mid + 1]) {
                ans++;
                for (int i = l; i <= mid; i++) {
                    swap(p[i], p[i - l + mid + 1]);
                }
            }
        };
        calc(0, m - 1);
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (p[i] != i + 1) {
                flag = false;
            }
        }
        if (flag) {
            cout << ans << '\n';
        }
        else {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
