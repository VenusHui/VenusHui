/**
 * @platform: Little Red Book
 * @problem: LittleRedBook_testB 
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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), tmp(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == num) num++;
        }
        int ans = n - num + 1;
        if (ans % k == 0) cout << ans / k << '\n';
        else cout << ans / k + 1 << '\n';
    }

    return 0;
}
