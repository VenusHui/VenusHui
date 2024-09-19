/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-21
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
        string s;
        cin >> s;
        int ans = 0;
        for (auto& i : s) {
            ans = max(ans, i - 'a' + 1);
        }
        cout << ans << '\n';
    }

    return 0;
}
