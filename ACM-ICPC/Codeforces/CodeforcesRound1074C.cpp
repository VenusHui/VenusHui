/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1074C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-18
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        set<int> s;
        for (int i = 0; i < n; i++) s.insert(a[i]);
        vector<int> b;
        for (auto& e : s) b.push_back(e);
        n = b.size();
        int prev = b[0], maxn = -0x3f3f3f3f, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (b[i] == prev + 1) {
                cnt++;
            }
            else {
                maxn = max(maxn, cnt);
                cnt = 1;
            }
            prev = b[i];
        }
        maxn = max(maxn, cnt);
        cout << maxn << '\n';
    }

    return 0;
}
