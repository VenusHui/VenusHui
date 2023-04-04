/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#863A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-04
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        string s;
        cin >> s;
        string ans = s;
        for (int i = 0; i < n; i++) {
            string tmp = s;
            tmp.insert(tmp.begin() + i, d + '0');
            if (tmp[0] != '0') ans = max(ans, tmp);
        }
        s += d + '0';
        cout << max(ans, s) << '\n';
    }

    return 0;
}
