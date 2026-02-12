/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1062A
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
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - 1]) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
