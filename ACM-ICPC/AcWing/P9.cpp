/**
 * @platform: AcWing
 * @problem: P9 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-03-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n), w(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int x, y;
            cin >> x >> y;
            v[i].push_back(x);
            w[i].push_back(y);
        }
    }
    vector<int> dp(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            int size = v[i].size();
            for (int k = 0; k < size; k++) {
                if (j - v[i][k] >= 0) dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
