/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#836A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-25
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
        string s;
        cin >> s;
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        cout << s << tmp << '\n';
    }

    return 0;
}
