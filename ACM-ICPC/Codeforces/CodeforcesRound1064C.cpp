/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1062C
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-11-18
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(a[i], a[(i + 1) % n]);
        }
        ans -= *max_element(a.begin(), a.end());
        cout << ans << '\n';
    }
    return 0;
}
