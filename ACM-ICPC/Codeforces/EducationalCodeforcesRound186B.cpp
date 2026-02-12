/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound186B
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
        int a, b;
        cin >> a >> b;
        int layer1 = 0, layer2 = 0;
        int c1 = max(a, b), c2 = min(a, b);
        for (int i = 0; c1 >= 0 && c2 >= 0; i++) {
            if (i % 2 == 0) {
                c2 -= pow(2, i);
            }
            else {
                c1 -= pow(2, i);
            }
            if (c1 >= 0 && c2 >= 0) layer1++;
        }
        c1 = max(a, b), c2 = min(a, b);
        for (int i = 0; c1 >= 0 && c2 >= 0; i++) {
            if (i % 2 == 0) {
                c1 -= pow(2, i);
            }
            else {
                c2 -= pow(2, i);
            }
            if (c1 >= 0 && c2 >= 0) layer2++;
        }
        cout << max(layer1, layer2) << '\n';
    }
    return 0;
}
