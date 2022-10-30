/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#831E 
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
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 2; i < n + 1; i++) {
        cin >> p[i];
    }
    vector<bool> vis(n + 1, true);
    vector<int> calc(n + 1, 0);
    for (int i = 0; i < n + 1; i++) {
        vis[p[i]] = false;
        calc[p[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << calc[i] << " ";
    }
    cout << '\n';
    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        if (vis[i] || calc[i] == 1) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
