/**
 * @platform: Nowcoder_Tencent
 * @problem: tencent_testC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> tmp(n);
    for (int i = 0; i < n; i++) {
        tmp[i] = i + 1;
    }
    auto check = [&] (vector<int>& x) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (b[j] < b[i]) {
                    if (x[j] >= x[i]) return false;
                }
            }
        }
        return true;
    };
    int ans = 0x3f3f3f3f;
    do {
        int x = 0;
        if (check(tmp)) {
            for (int i = 0; i < n; i++) {
                x += abs(a[i] - tmp[i]);
            }
            ans = min(ans, x);
        }
    } while (next_permutation(tmp.begin(), tmp.end()));
    cout << ans << '\n';

    return 0;
}
