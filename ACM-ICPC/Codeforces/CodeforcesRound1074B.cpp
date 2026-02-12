/**
 * @platform: Codeforce
 * @problem: CodeforcesRound1074B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-18
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
        int maxn = -0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxn = max(maxn, a[i]);
        }
        cout << maxn * n << '\n';
    }

    return 0;
}
