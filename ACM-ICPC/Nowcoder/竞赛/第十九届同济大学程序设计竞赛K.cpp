/**
 * @platform: Nowcoder
 * @problem: 第十九届同济大学程序设计竞赛K 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-21
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
    vector<string> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int j = 0; j < m; j++) {
        ll num = 0;
        vector<ll> tmp(5, 0);
        for (int i = 0; i < n; i++) {
            tmp[res[i][j] - 'A']++;
        }
        for (int i = 0; i < 5; i++) {
            num = max(num, tmp[i]);
        }
        ans += num * a[j];
    }
    cout << ans << '\n';

    return 0;
}
