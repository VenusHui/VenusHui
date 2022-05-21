/**
 * @platform: Nowcoder
 * @problem: 武汉理工大学第三届程序设计竞赛N
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
    int n;
    cin >> n;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    res.push_back(1e9 + 5);
    sort(res.begin(), res.end());
    vector<ll> src;
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        if (res[i] + 1 == res[i + 1]) {
            tmp++;
        }
        else {
            src.push_back(tmp);
            tmp = 1;
        }
    }
    ll ans = 0;
    int size = src.size();
    for (int i = 0; i < size; i++) {
        ans += src[i] * (src[i] - 1) / 2;
    }
    cout << ans << '\n';

    return 0;
}
