/**
 * @platform: AcWing
 * @problem: P797 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-11
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1);
    function<void(int, int, int)> insert = [&] (int l, int r, int c) {
        pre[l] += c, pre[r + 1] -= c;
    };
    for (int i = 0; i < n; i++) {
        insert(i, i, a[i]);
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l - 1, r - 1, c);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + pre[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
