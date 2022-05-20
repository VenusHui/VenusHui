/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#788C Where is the Pizza?
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-05-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int mod = 1e9 + 7;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n), d(n);
        vector<bool> res(n + 1, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            if (d[i]) {
                c[i] = d[i];
            }
            res[d[i]] == true;
        }
        for (int i = 0; i < n; i++) {
            
        }
    }

    return 0;
}
