/**
 * @platform: Codeforeces
 * @problem: CodeforcesRound#799B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-13
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
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        int num = 0;
        for (auto& it : mp) {
            if (it.second >= 1) {
                num += it.second - 1;
            }
        }
        cout << n - (num + 1) / 2 * 2 << '\n';
    }

    return 0;
}
