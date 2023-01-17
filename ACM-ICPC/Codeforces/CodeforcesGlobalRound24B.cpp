/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound24B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-26
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, maxn = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxn = max(maxn, a[i]);
        }
        int num = gcd(a[0], a[1]);
        for (int i = 2; i < n; i++) {
            num = gcd(num, a[i]);
        }
        cout << maxn / num << '\n';
    }

    return 0;
}
