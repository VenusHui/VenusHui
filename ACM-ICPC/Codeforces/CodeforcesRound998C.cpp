/**
 * @platform: Codeforces
 * @problem: CodeforcesRound998C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-19
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
        vector<int> x(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            mp[x[i]]++;
        }

        int ans = 0;
        sort(x.begin(), x.end());
        for (int i = 0; i < n; i++) {
            if (mp[k - x[i]] > 0) {
                mp[k - x[i]]--;
                ans++;
            }
        }
        cout << ans / 2 << '\n';
    }

    return 0;
}
