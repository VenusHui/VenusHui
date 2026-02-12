/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1074E 
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        string s;
        cin >> s;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lq, rq;
        for (int i = 0; i < n; i++) {
            auto upper_it = upper_bound(b.begin(), b.end(), a[i]);
            auto lower_it = lower_bound(b.begin(), b.end(), a[i]);
            int left = 0x3f3f3f3f, right = 0x3f3f3f3f;
            if (lower_it != b.begin()) {
                left = a[i] - *(lower_it - 1);
            }
            if (upper_it != b.end()) {
                right = *upper_it - a[i];
            }
            lq.emplace(make_pair(left, a[i]));
            rq.emplace(make_pair(right, a[i]));
        }
        int cnt = 0, ans = n;
        unordered_map<int, int> delmp;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'L') {
                cnt--;
            }
            else if (s[i] == 'R') {
                cnt++;
            }
            if (cnt < 0) {
                int delta = abs(cnt);
                while (!lq.empty() && lq.top().first <= delta) {
                    if (delmp[lq.top().second] == 0) {
                        delmp[lq.top().second]++;
                        ans--;
                    }
                    lq.pop();
                }
            }
            else {
                int delta = abs(cnt);
                while (!rq.empty() && rq.top().first <= delta) {
                    if (delmp[rq.top().second] == 0) {
                        delmp[rq.top().second]++;
                        ans--;
                    }
                    rq.pop();
                }
            }
            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}
