/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1054C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-10-01
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (mp[i] == 0) ans++;
        }
        if (mp[k] >= ans) ans = mp[k];
        cout << ans << '\n';
    }

    return 0;
}
