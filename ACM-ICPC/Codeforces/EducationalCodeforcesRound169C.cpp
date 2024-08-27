/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound169C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-08-27
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        int ans_a = 0, ans_b = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                if (a[i] < a[i - 1] && k >= 0) {
                    int diff = min(a[i - 1] - a[i], k);
                    a[i] += diff;
                    k -= diff;
                }
                ans_b += a[i];
            }
            else ans_a += a[i];
        }
        cout << ans_a - ans_b << '\n';
    }
    return 0;
}
