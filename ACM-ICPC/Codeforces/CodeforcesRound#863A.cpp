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
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' < d) {
                flag = true;
                s.insert(s.begin() + i, d + '0');
                break;
            }
        }
        if (!flag) s += d + '0';
        cout << s << '\n';
    }

    return 0;
}
