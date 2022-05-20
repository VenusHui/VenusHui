/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#792D 
 * @version: Contest Version - Unsolved
 * @author: VenusHui
 * @date: 2022-05-19
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
        int n, k;
        cin >> n >> k;
        vector<int> res(n);
        vector<vector<ll>> dp(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        function<bool(int)> bound = [&] (int num) {
            if (num > k) {
                return false;
            }
            return true;
        };
        ll ans = 2e5 * 1e9;
        function<void(int, int, int)> dfs = [&] (int pos, int num, ll tmp) {
            if (pos > n) {
                ans = min(ans, tmp);
                return;
            }
            if (tmp > ans) {
                return;
            }
            if (num <= k) {
                dfs(pos + 1, num, tmp + res[pos] + num);
                dfs(pos + 1, num + 1, tmp);
            }
        };
        dfs(0, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}
