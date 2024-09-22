/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#795A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-31
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
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num % 2 == 0) {
                ans++;
            }
        }
        cout << min(ans, n - ans) << '\n';
    }

    return 0;
}
