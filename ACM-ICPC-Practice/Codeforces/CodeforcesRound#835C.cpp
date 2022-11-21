/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-21
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
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> tmp = s;
        sort(tmp.begin(), tmp.end());
        int max1 = tmp[n - 1], max2 = tmp[n - 2];
        for (int i = 0; i < n; i++) {
            if (s[i] == max1) {
                cout << max1 - max2 << ' ';
            }
            else {
                cout << s[i] - max1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
