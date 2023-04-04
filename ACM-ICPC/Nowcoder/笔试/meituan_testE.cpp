/**
 * @platform: Meituan
 * @problem: meituan_testE 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-01
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n + 1), c(n + 1);
    for (int i = 2; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        tree[p[i]].push_back(i);
    }
    function<int(int)> calc = [&] (int x) {
        if (tree[x].empty()) return 1;
        if (c[x] == 1) {
            return calc(tree[x][0]) + calc(tree[x][1]);
        }
        else {
            return calc(tree[x][0]) xor calc(tree[x][1]);
        }
    };
    cout << calc(1) << '\n';

    return 0;
}
