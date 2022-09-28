/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#821D1 
 * @version: Contest Version UnSolved
 * @author: VenusHui
 * @date: 2022-09-19
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
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                res.push_back(i);
            }
        }
        int size = res.size();
        if (size == 0) {
            cout << "0" << '\n';
            continue;
        }
        if (size % 2 != 0) {
            cout << "-1" << '\n';
            continue;
        }
        if (size == 2) {
            if (n == 2) {
                cout << x << '\n';
                continue;
            }
            if (2 * y < x) {
                cout << 2 * y << '\n';
            }
            else {
                cout << x << '\n';
            }
            continue;
        }
        ll ans = y * size / 2;
        cout << ans << '\n';
    }

    return 0;
}
