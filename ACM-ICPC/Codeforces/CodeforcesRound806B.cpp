/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-12
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
        string s;
        cin >> s;
        vector<int> res(26, 0);
        for (int i = 0; i < n; i++) {
            if (res[s[i] - 'A'] == 0) {
                ans += 2;
                res[s[i] - 'A']++;
            }
            else {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
