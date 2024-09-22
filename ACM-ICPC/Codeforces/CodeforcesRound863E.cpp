/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#863E 
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
        ll k;
        cin >> k;
        string s;
        while (k) {
            s += k % 9 + '0';
            k /= 9;
        }
        reverse(s.begin(), s.end());
        for (auto& e : s) {
            if (e >= '4') e++;
        }
        cout << s << '\n';
    }

    return 0;
}
