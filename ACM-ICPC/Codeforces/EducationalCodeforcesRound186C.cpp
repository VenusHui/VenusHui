/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound186C
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-12-31
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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        int num_i = 0, num_k = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (a[(i + j) % n] >= b[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) num_i++;
        }
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (c[(i + j) % n] <= b[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) num_k++;
        }
        cout << 1LL * num_i * num_k * n << '\n';
    }
    return 0;
}
