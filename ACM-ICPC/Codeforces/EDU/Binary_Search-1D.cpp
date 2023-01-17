/**
 * @platform: Codeforces
 * @problem: Binary_Search-1D 
 * @version: EDU
 * @author: VenusHui
 * @date: 2022-05-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> res[i];
    }
    sort(res.begin() + 1, res.end());
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= res[1]) {
            x = 0;
        }
        else {
            int l = 1, r = n;
            while (l < r) {
                int m = (l + r + 1) >> 1;
                if (res[m] < x) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            x = l;
        }
        if (y >= res[n]) {
            y = n + 1;
        }
        else {
            int l = 1, r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                if (res[m] <= y) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            y = l;
        }
        cout << y - x - 1 << '\n';
    }

    return 0;
}
