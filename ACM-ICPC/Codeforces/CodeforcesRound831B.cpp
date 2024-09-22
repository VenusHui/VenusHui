/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#831B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-29
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
        ll ans = 0;
        vector<pair<ll, ll>> res(n);
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            res[i] = make_pair(max(a, b), min(a, b));
            ans += (a + b) * 2;
        }
        sort(res.begin(), res.end(), [&] (pair<ll, ll>& a, pair<ll, ll>& b) {
            return a.first > b.first || a.first == b.first && a.second > b.second;
        });
        for (int i = 0; i < n - 1; i++) {
            ll tmp = min(res[i].first, res[i + 1].first);
            ans -= tmp * 2;
        }
        cout << ans << '\n';
    }

    return 0;
}
