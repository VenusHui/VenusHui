/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1065A
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-11-21
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
        int chicken_num = 0, ans = 0;
        while (2 * chicken_num <= n) {
            if ((n - 2 * chicken_num) % 4 == 0) {
                ans++;
            }
            chicken_num++;
        }
        cout << ans << '\n';
    }
    return 0;
}
