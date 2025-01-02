/**
 * @platform: Codeforces
 * @problem: CodeforcesRound991E 
 * @version: Contest Version TLE
 * @author: VenusHui
 * @date: 2024-12-05
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
        string a, b, c;
        cin >> a >> b >> c;
        int an = a.size(), bn = b.size();
        int gans = 0x3f3f3f3f;
        function<int(string&, int, int, int)> dfs = [&] (string& s, int apos, int bpos, int ans) {
            if (ans >= gans) return 0x3f3f3f3f;
            if (apos == an && bpos == bn) {
                gans = min(ans, gans);
                return ans;
            }
            int res = 0x3f3f3f3f;
            if (apos < an) {
                string ns = s + a[apos];
                int delta = c[ns.size() - 1] != a[apos] ? 1 : 0;
                ans += delta;
                int ansa = dfs(ns, apos + 1, bpos, ans);
                ans -= delta;
                res = min(ansa, res);
            }
            if (bpos < bn) {
                string ns = s + b[bpos];
                int delta = c[ns.size() - 1] != b[bpos] ? 1 : 0;
                ans += delta;
                int ansb = dfs(ns, apos, bpos + 1, ans);
                ans -= delta;
                res = min(ansb, res);
            }
            return res;
        };
        string init = "";
        int ans = dfs(init, 0, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}
