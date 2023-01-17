/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 8;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans;
        vector<string> tmp(n);
        vector<set<string>> res(maxn);
        for (int i = 0; i < n; i++) {
            cin >> tmp[i];
            res[tmp[i].size() - 1].insert(tmp[i]);
        }
        for (int i = 0; i < n; i++) {
            bool flag = false;
            int size = tmp[i].size();
            for (int j = 0; j < size - 1; j++) {
                if (res[j].find(tmp[i].substr(0, j + 1)) != res[j].end() && res[size - j - 2].find(tmp[i].substr(j + 1, size - 1)) != res[size - j - 2].end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ans += "1";
            }
            else {
                ans += "0";
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
