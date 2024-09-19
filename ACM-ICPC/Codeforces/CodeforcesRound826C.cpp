/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#826C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-11
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }
        int res = n;
        for (int i = 0; i < n; i++) {
            if (pre[n - 1] % pre[i] == 0) {
                int ans = 0;
                int tmp = 0, per = 0;
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (tmp < pre[i]) {
                        tmp += a[j];
                        per++;
                    }
                    if (tmp == pre[i]) {
                        ans = max(ans, per);
                        tmp = 0;
                        per = 0;
                    }
                    else if (tmp > pre[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = min(res, ans);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
