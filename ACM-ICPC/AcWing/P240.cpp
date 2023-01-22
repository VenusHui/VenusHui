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
    vector<pair<int, int>> disjoint_set;
    function<pair<int, int>(int)> find = [&] (int x) {
        if (disjoint_set[x].first != x) {
            pair<int, int> t = find(disjoint_set[x].first);
            disjoint_set[x].second += disjoint_set[disjoint_set[x].first].second;
            disjoint_set[x].first = t.first;
        }
        return disjoint_set[x];
    };
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) disjoint_set.push_back(make_pair(i, 0));
    int ans = 0;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        pair<int, int> px = find(x), py = find(y);
        if (d == 1) {
            if (px.first == py.first && (px.second - py.second) % 3) ans++;
            else if (px.first != py.first) {
                disjoint_set[px.first].second = disjoint_set[y].second - disjoint_set[x].second;
                disjoint_set[px.first].first = py.first;
            }
        }
        else if (d == 2) {
            if (px.first == py.first && (px.second - py.second - 1) % 3) ans++;
            else if (px.first != py.first) {
                disjoint_set[px.first].second = disjoint_set[y].second - disjoint_set[x].second + 1;
                disjoint_set[px.first].first = py.first;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
