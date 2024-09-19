/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    const int maxn = 1001;
    vector<vector<bool>> res(maxn, vector<bool>(maxn));
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
             if (gcd(i, j) == 1) {
                res[i][j] = true;
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), tmp(maxn);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tmp[a[i]] = max(tmp[a[i]], i + 1);
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < maxn; j++) {
                if (res[a[i]][j] && tmp[j] != 0) {
                    ans = max(ans, i + 1 + tmp[j]);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
