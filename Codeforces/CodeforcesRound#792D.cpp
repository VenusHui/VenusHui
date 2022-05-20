/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#792D 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-05-20
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
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
            ans += res[i];
            res[i] += i + 1;
        }
        if (k >= n) {
            cout << "0" << '\n';
            continue;
        }
        sort(res.begin(), res.end(), [](int& a, int& b) {
            return a > b;
        });
        for (int i = 0; i < k; i++) {
            ans -= res[i];
            ans += n - i;
        }
        cout << ans << '\n';
    }

    return 0;
}
