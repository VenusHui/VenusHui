/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#797C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-07
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
        vector<int> s(n), f(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        vector<int> d(n);
        int cnt = s[0];
        for (int i = 0; i < n; i++) {
            if (s[i] <= cnt) {
                d[i] = f[i] - cnt;
            }
            else {
                d[i] = f[i] - s[i];
            }
            cnt = f[i];
        }
        for (int i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
