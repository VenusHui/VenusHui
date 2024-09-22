/**
 * @platform: Codeforces
 * @problem: CodeforcesRound973A 
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0, p = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= k) {
                ans += a[i];
            }
            if (a[i] == 0 && ans > 0) {
                ans--;
                p++;
            }
        }
        cout << p << '\n';
    }

    return 0;
}
