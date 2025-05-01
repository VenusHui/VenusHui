/**
 * @platform: Codeforces
 * @problem: CodeforcesRound999B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-20
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
        sort(a.begin(), a.end());
        function<pair<int, int>(int)> get_pair = [&] (int i) {
            if (i == 0) {
                for (int j = 2; j < n - 1; j++) {
                    if (a[j + 1] - a[j] < 2 * a[i]) {
                        return make_pair(j, j + 1);
                    }
                }
                return make_pair(2, 3);
            }
            if (i == n - 2) return make_pair(n - 4, n - 3);
            return make_pair(i - 1, i + 2);
        };
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                pair<int, int> e = get_pair(i);
                if (2 * a[i] + a[e.first] > a[e.second]) {
                    cout << a[e.first] << " " << a[i] << " " << a[i + 1] << " " << a[e.second] << '\n';
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
