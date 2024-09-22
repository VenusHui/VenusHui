/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#831C 
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        // fix 1
        ll w1 = a[0];
        for (int i = 1; i < n - 1; i++) {
            ll w2 = a[i + 1], w3 = a[i];
            ans = max(ans, 2 * w2 - w1 - w3);
        }
        w1 = a[n - 1];
        for (int i = 0; i < n - 2; i++) {
            ll w2 = a[i], w3 = a[i + 1];
            ans = max(ans, w1 + w3 - 2 * w2);
        }        
        cout << ans << '\n';
    }

    return 0;
}
