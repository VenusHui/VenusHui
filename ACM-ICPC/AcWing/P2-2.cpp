/**
 * @platform: AcWing
 * @problem: P2-2 
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
    // 滚动数组优化
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    vector<int> dp(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
