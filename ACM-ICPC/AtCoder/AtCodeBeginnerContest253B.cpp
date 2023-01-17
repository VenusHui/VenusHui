/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest253B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-28
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
    vector<string> grid(n);
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'o') {
                res.push_back(make_pair(i, j));
            }
        }
    }
    cout << abs(res[0].first - res[1].first) + abs(res[0].second - res[1].second) << '\n';

    return 0;
}
