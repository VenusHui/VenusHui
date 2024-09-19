/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#794A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-26
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
        int n, sum = 0;
        cin >> n;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
            sum += res[i];
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (sum - res[i] == (n - 1) * res[i]) {
                ans = true;
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
