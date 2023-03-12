/**
 * @platform: AcWing
 * @problem: P3-3 
 * @version: Toturial Version
 * @author: VenusHui
 * @date: 2023-03-10
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
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = v[i - 1]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - v[i - 1]] + w[i - 1]);
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
