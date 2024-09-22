/**
 * @platform: Codeforces
 * @problem: CodeforcesRound974C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-21
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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n <= 2) {
            cout << "-1" << '\n';
            continue;
        }
        sort(a.begin(), a.end());
        ll mid = a[n / 2], sum = accumulate(a.begin(), a.end(), 0LL);
        ll l = 0LL, r = 1LL * 4 * sum;
        while (l < r) {
            ll m = l + (r - l) / 2;
            if (mid >= 1.0 * (sum + m) / n / 2) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        cout << l << '\n';
    }

    return 0;
}
