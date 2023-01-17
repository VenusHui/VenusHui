/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound136B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-29
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
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        vector<set<int>> a(n);
        a[0].insert(d[0]);
        bool flag = true;
        for (int i = 0; i < n - 1 && flag; i++) {
            for (auto& it : a[i]) {
                int minn = min(it + d[i + 1], it - d[i + 1]);
                int maxn = max(it + d[i + 1], it - d[i + 1]);
                if (minn >= 0) {
                    a[i + 1].insert(minn);
                    a[i + 1].insert(maxn);
                }
                else if (maxn >= 0) {
                    a[i + 1].insert(maxn);
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (a[n - 1].size() != 1) {
            cout << "-1" << '\n';
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << *a[i].begin() << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
