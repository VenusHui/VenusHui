/**
 * @platform: AcWing
 * @problem: P2186 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int i = 0;
    for (int j = 0; j < m; j++) {
        if (i < n && a[i] == b[j]) {
            i++;
        }
    }
    if (i == n) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}
