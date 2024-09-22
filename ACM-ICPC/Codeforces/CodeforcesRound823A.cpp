/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#823A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-25
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 101;
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> res(maxn);
        for (int i = 0; i < n; i++) {
            res[a[i]]++;
        }
        for (int i = 0; i < maxn; i++) {
            ans += min(c, res[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
