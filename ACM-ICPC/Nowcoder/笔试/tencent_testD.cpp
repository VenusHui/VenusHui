/**
 * @platform: Nowcoder_Tencent
 * @problem: tencent_testD 
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> mulpre(n + 1, 1);
    vector<int> xorpre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        mulpre[i + 1] = mulpre[i] * a[i];
        xorpre[i + 1] = xorpre[i] ^ a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((mulpre[j + 1] / mulpre[i]) == (xorpre[j + 1] ^ xorpre[i])) {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
