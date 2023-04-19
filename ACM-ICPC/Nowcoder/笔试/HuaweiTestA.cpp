/**
 * @platform: Huawei
 * @problem: HuaweiTestA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-19
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
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back(make_pair(u, 1));
        a.push_back(make_pair(v + 1, -1));
    }
    map<int, int> mp;
    for (auto& e : a) mp[e.first] += e.second;
    for (auto& e : mp) {
        if (e.second) b.push_back(e);
    }
    int ans = 0;
    int task_num = 0;
    int s = b[0].first, e = b[b.size() - 1].first;
    int pos = 0;
    for (int i = s; i <= e - 1; i++) {
        if (i == b[pos].first) {
            task_num += b[pos].second;
            pos++;
        }
        if (task_num == 0) ans += 1;
        if (task_num == 1) ans += 3;
        if (task_num >= 2) ans += 4;
    }
    cout << ans << '\n';

    return 0;
}
