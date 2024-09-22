/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806F 
 * @version: Contest Version - UnSolved
 * @author: VenusHui
 * @date: 2022-07-13
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
        vector<int> a(n + 1);
        vector<pair<int, int>> res;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < i) {
                res.push_back(make_pair(a[i], i));
            }
        }
        ll ans = 0, tmp = 0;
        int size = res.size();
        for (int i = 1; i < size; i++) {
            if (res[0].second < res[i].first) {
                tmp++;
            }
        }
        ans = (1 + tmp) * tmp / 2;
        cout << ans << '\n';
    }

    return 0;
}
