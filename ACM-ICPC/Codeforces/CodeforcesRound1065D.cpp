/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1065D
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-11-24
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
        int n;
        cin >> n;
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++) cin >> p[i];
        vector<int> pre(n), suf(n);
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            pre[i] = min(minn, p[i]);
            minn = pre[i];
        }
        int maxn = -0x3f3f3f3f;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(maxn, p[i]);
            maxn = suf[i];
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (pre[i] > suf[i + 1] && i + 1 <= n - 1) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
