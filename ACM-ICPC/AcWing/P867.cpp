/**
 * @platform: AcWing
 * @problem: P867 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-18
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    function<vector<pair<int, int>>(int)> get_prime_fact = [&] (int n) {
        vector<pair<int, int>> res;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                int s = 0;
                while (n % i == 0) {
                    n /= i;
                    s++;
                }
                res.push_back({i, s});
            }
        }
        if (n > 1) res.push_back({n, 1});
        return res;
    };
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto facts = get_prime_fact(n);
        for (auto& e : facts) {
            cout << e.first << " " << e.second << '\n';
        }
        cout << '\n';
    }

    return 0;
}
