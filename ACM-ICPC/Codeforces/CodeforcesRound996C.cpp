/**
 * @platform: Codeforces
 * @problem: CodeforcesRound996C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-12
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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        ll sum = 0;
        int size = s.size();
        int x = 0, y = 0;
        for (int p = 0; p <= size; p++) {
            if (s[p] == 'D' || p == size) {
                ll res = 0;
                for (int i = 0; i < m; i++) {
                    res -= a[x][i];
                }
                a[x][y] = res;
                x++;
            }
            else {
                ll res = 0;
                for (int i = 0; i < n; i++) {
                    res -= a[i][y];
                }
                a[x][y] = res;
                y++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
