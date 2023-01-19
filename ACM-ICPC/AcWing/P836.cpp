/**
 * @platform: AcWing
 * @problem: P836 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> disjoint_set;
    function<int(int)> find = [&] (int x) {
        if (disjoint_set[x] != x) disjoint_set[x] = find(disjoint_set[x]);
        return disjoint_set[x];
    };
    for (int i = 0; i <= n; i++) {
        disjoint_set.push_back(i);
    }
    while (m--) {
        string oper;
        int a, b;
        cin >> oper >> a >> b;
        if (oper == "M") disjoint_set[find(a)] = find(b);
        if (oper == "Q") {
            if (find(a) == find(b)) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }

    return 0;
}
