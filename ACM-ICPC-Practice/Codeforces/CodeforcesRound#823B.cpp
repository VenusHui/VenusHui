/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#823B 
 * @version: Contest Version UnSolved (Wa Pretest3)
 * @author: VenusHui
 * @date: 2022-09-25
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
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        int l = 1 << 30, r = -1 * (1 << 30);
        for (int i = 0; i < n; i++) {
            l = min(l, x[i] - t[i]);
            r = max(r, x[i] + t[i]);
        }
        double ans = 1.0 * (l + r) / 2;
        cout << ans << '\n';
    }

    return 0;
}
