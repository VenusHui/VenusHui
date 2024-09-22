/**
 * @platform: Codeforces
 * @problem: CodeforcesRound972B1
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-18
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(q), b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < q; i++) cin >> a[i];
        sort(b.begin(), b.end());
        for (int i = 0; i < q; i++) {
            int speed = 2;
            auto lit = upper_bound(b.begin(), b.end(), a[i]);
            auto rit = upper_bound(b.begin(), b.end(), a[i]);
            int lt, rt;
            if (lit == b.begin() && *b.begin() != 1) {
                lt = 1;
                speed--;
            } else lt = *(--lit);
            if (rit == b.end()) {
                rt = n;
                speed--;
            } else rt = *rit;
            cout << (rt - lt) / speed << '\n';
        }
    }

    return 0;
}
