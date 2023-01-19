/**
 * @platform: AcWing
 * @problem: P240 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-20
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<int, char>> disjoint_set;
    function<int(int)> find = [&] (int x) {
        if (disjoint_set[x].first != x) disjoint_set[x].first = find(disjoint_set[x].first);
        return disjoint_set[x].first;
    };
    function<bool(int, int)> together = [&] (int a, int b) {
        return find(a) == find(b);
    };
    function<void(int, int)> set_union = [&] (int a, int b) {
        if (together(a, b)) return;
        disjoint_set[find(a)].first = find(b);
    };
    function<int(int)> set_size = [&] (int a) {
        return disjoint_set[find(a)].second;
    };
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) disjoint_set.push_back(i, 'x');
    int ans = 0;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n || d == 2 && x == y) ans++, continue;
        if (d == 1) {
            set_union(x, y);
        }
        if (d == 2) {

        }
    }

    return 0;
}
