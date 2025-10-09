/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1054D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-10-02
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
        string s;
        cin >> s;
        function<ll(string)> calc = [&] (string s) {
            // calculate the number of the operations to make all of the 'a' in the middle of the string
            ll dist = 0;
            vector<ll> pos;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a') pos.push_back(i);
            }
            ll mid = pos.size() / 2, count = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a') {
                    dist += abs(pos[mid] - i) - abs(mid - count);
                    count++;
                }
            }
            return dist;
        };
        string rs;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') rs.push_back('b');
            if (s[i] == 'b') rs.push_back('a');
        }
        cout << min(calc(s), calc(rs)) << '\n';
    }

    return 0;
}
