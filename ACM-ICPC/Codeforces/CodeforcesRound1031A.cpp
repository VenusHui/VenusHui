/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1031A
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-06-16
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
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int ans = 0, anum = 0, bnum = 0;
        if (x < y) {
            anum = k >= a ? (k - a) / x + 1 : 0;
            bnum = (k - x * anum) >= b ? (k - x * anum - b) / y + 1 : 0;
            ans = max(anum + bnum, ans);
        }
        else {
            bnum = k >= b ? (k - b) / y + 1 : 0;
            anum = (k - y * bnum) >= a ? (k - y * bnum - a) / x + 1 : 0;
            ans = max(anum + bnum, ans);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
