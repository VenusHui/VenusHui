/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#829C1 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-23
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
        if (n % 2 != 0) {
            cout << "-1" << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i += 2) {
            if (a[i] == a[i + 1]) {
                ans.push_back(make_pair(i + 1, i + 2));
            }
            else {
                ans.push_back(make_pair(i + 1, i + 1));
                ans.push_back(make_pair(i + 2, i + 2));
            }
        }
        int size = ans.size();
        cout << size << '\n';
        for (int i = 0; i < size; i++) {
            cout << ans[i].first << " " << ans[i].second << '\n';
        }
    }

    return 0;
}
