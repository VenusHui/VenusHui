/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound131C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-08
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
        vector<int> a(m);
        vector<vector<int>> w(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            w[a[i]].push_back(i + 1);
        }
        int mmax = 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = w[i + 1].size();
            mmax = max(mmax, res[i]);
        }
        function<bool(int)> check = [&] (int x) {
            ll tmp = 0;
            for (int i = 0; i < n; i++) {
                if (res[i] >= x) {
                    tmp += res[i] - x;
                }
                else {
                    tmp -= (x - res[i]) / 2;
                }
            }
            if (tmp <= 0) {
                return true;
            }
            else {
                return false;
            }
        };
        int l = 0, r = mmax + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }

    return 0;
}
