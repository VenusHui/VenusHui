/**
 * @platform: AcWing
 * @problem: P841 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-28
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const ull p = 131;
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<ull> hash(n + 1), base(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        base[i] = base[i - 1] * p;
        hash[i] = hash[i - 1] * p + s[i - 1];
    }
    function<ull(int, int)> query = [&] (int l, int r) {
        return hash[r + 1] - hash[l] * base[r - l + 1];
    };
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (query(l1 - 1, r1 - 1) == query(l2 - 1, r2 - 1)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}
