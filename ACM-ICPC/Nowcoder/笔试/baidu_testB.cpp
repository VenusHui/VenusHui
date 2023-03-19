/**
 * @platform: Nowcoder_Baidu
 * @problem: baidu_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 50000;
    const string strd = "red";
    vector<ll> a(maxn), pre(maxn);
    for (int i = 0; i < maxn; i++) a[i] = i + 1;
    partial_sum(a.begin(), a.end(), pre.begin());
    int x;
    cin >> x;
    string ans;
    int loop = 0;
    while (x) {
        int l = 0, r = maxn - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (x > pre[m]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        if (l > 0) {
            string tmp(l, strd[loop % 3]);
            ans += tmp;
            x -= pre[l - 1];
            loop++;
        }
        else {
            break;
        }
    }
    if (x == 1) {
        ans += strd[loop % 3];
    }
    else {
        ans += strd[loop % 3];
        loop++;
        ans += strd[loop % 3];
    }
    cout << ans << '\n';

    return 0;
}
