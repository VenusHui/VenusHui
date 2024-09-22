/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#788A Prof. Slim
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-19
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
        vector<int> res(n);
        int fnum = 0;
        for (int i = 0; i < n; i++) {
            cin >> res[i];
            if (res[i] < 0) {
                fnum++;
            }
            res[i] = abs(res[i]);
        }
        for (int i = 0; i < fnum; i++) {
            res[i] *= -1;
        }
        bool ans = true;
        for (int i = 0; i < n - 1; i++) {
            if (res[i] > res[i + 1]) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
