/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1074D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-18
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
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> diff(n, 0);
        vector<int> base_version(n, 0);
        vector<int> current_value(n);
        int global_version = 0;
        bool need_reset = false;
        for (int i = 0; i < n; i++) {
            current_value[i] = a[i];
        }
        for (int i = 0; i < m; i++) {
            int b, c;
            cin >> b >> c;
            b--;
            if (need_reset) {
                global_version++;
                need_reset = false;
                diff[b] = c;
                base_version[b] = global_version;
            } else {
                if (base_version[b] < global_version) {
                    diff[b] = c;
                    base_version[b] = global_version;
                } else {
                    diff[b] += c;
                }
            }
            int current_base = (base_version[b] == global_version) ? a[b] : current_value[b];
            if (current_base + diff[b] > h) {
                need_reset = true;
            } else {
                current_value[b] = current_base + diff[b];
            }
        }
        for (int j = 0; j < n; j++) {
            if (base_version[j] == global_version && !need_reset) {
                cout << a[j] + diff[j] << " ";
            } else {
                cout << a[j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
