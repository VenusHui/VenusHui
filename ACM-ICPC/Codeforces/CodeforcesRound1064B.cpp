/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1062B
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
        int a, b, n;
        cin >> a >> b >> n;

        int m = n;
        bool flag1 = true, flag2 = true;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (flag1 && 1.0 * b == 1.0 * a / m) {
                flag1 = false;
                continue;
            }
            else if (1.0 * b > 1.0 * a / m) {
                ans1 = 1;
                break;
            }
            else {
                ans2 = 1;
                break;
            }
            m--;
        }
        for (int i = 1; i <= n; i++) {
            if (flag2 && 1.0 * b == 1.0 * a / i) {
                flag2 = false;
                continue;
            }
            else if (1.0 * b > 1.0 * a / i) {
                ans1 = 1;
                break;
            }
            else {
                ans2 = 1;
                break;
            }
        }
        cout << max(ans1 + ans2, 1) << '\n';
    }
    
    return 0;
}
