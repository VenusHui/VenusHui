/**
 * @platform: Codeforces
 * @problem: CodeforcesRound998B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-19
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
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> p[i][j];
            sort(p[i].begin(), p[i].end());
        }
        vector<pair<int, int>> tmpv(n);
        for (int i = 0; i < n; i++) tmpv[i] = make_pair(p[i][0], i);
        sort(tmpv.begin(), tmpv.end());
        vector<int> cows(n);
        for (int i = 0; i < n; i++) cows[i] = tmpv[i].second;
        
        bool tmp = true;
        int cnt = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[cows[j]][i] > cnt) {
                    cnt = p[cows[j]][i];
                }
                else {
                    tmp = false;
                    break;
                }
            }
        }
        if (tmp) {
            for (int i = 0; i < n; i++) {
                cout << cows[i] + 1 << " ";
            }
            cout << '\n';
        }
        else cout << "-1" << '\n';
    }

    return 0;
}
