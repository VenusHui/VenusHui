/**
 * @platform: AcWing
 * @problem: P5 
 * @version: Tutorial Version
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
    vector<int> v, w;
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        int k = 1;
        while (k <= s) {
            v.push_back(k * x);
            w.push_back(k * y);
            s -= k, k *= 2;
        }
        if (s > 0) {
            v.push_back(s * x);
            w.push_back(s * y);
        }
    }
    n = v.size();
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - v[i - 1]] + w[i - 1]);
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
