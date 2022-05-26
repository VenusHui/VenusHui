/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#794B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-26
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
        vector<int> p(n);
        vector<bool> flag(n, false);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (!flag[i] && p[i] > p[i + 1]) {
                ans++;
                flag[i] = flag[i + 1] = true;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
