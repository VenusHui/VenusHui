/**
 * @platform: Huawei
 * @problem: HuaweiTestB 
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
    vector<vector<int>> tree(n);
    int edge_num, block_num;
    cin >> edge_num;
    for (int i = 0; i < edge_num; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }
    cin >> block_num;
    vector<bool> blocks(n, false);
    for (int i = 0; i < block_num; i++) {
        int x;
        cin >> x;
        blocks[x] = true;
    }
    vector<int> path(n, -1), len(n, 0x3f3f3f3f);
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> cnt = q.front();
        q.pop();
        len[cnt.first] = min(len[cnt.first], cnt.second);
        for (auto& e : tree[cnt.first]) {
            if (!blocks[e]) {
                q.push(make_pair(e, cnt.second + 1));
                path[e] = cnt.first;
            }
        }
    }
    for (auto& e : len) cout << e << " ";
    cout << '\n';
    int ans = -1, ans_len = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (tree[i].size() == 0) {
            if (len[i] < ans_len) {
                ans = i;
                ans_len = len[i];
            }
        }
    }
    if (ans == -1) {
        cout << "NULL" << '\n';
        return 0;
    }
    vector<int> ans_path;
    while (ans != -1) {
        ans_path.push_back(ans);
        ans = path[ans];
    }
    reverse(ans_path.begin(), ans_path.end());
    string s;
    int size = ans_path.size();
    for (int i = 0; i < size; i++) {
        s += to_string(ans_path[i]);
        if (i != size - 1) s += "->";
    }
    cout << s << '\n';

    return 0;
}
