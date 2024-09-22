/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#831D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-29
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        int buffer = n * m - 4, tmp = k;
        map<int, int> mp;
        bool ans = true;
        for (int i = 0; i < k; i++) {
            if (a[i] != tmp) {
                mp[a[i]]++;
                if (mp.size() > buffer) {
                    ans = false;
                }
            }
            else {
                tmp--;
                while (mp.find(tmp) != mp.end()) {
                    mp.erase(mp.find(tmp));
                    tmp--;
                }
            }
        }
        if (ans) {
            cout << "YA" << '\n';
        }
        else {
            cout << "TIDAK" << '\n';
        }
    }

    return 0;
}
