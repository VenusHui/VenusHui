/**
 * @platform: LittleRedBook_Cpp
 * @problem: LittleRedBook_CppA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-09
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
    vector<vector<int>> tree(n + 1);
    int root = (1 + n) * n / 2;
    for (int i = 0; i < n - 1; i++) {
        int s, t;
        cin >> s >> t;
        root -= s;
        tree[t].push_back(s);
    }
    vector<int> res(n + 1);
    function<int(int)> calc = [&] (int x) {
        int ans = 1;
        for (auto& e : tree[x]) {
            ans += calc(e);
        }
        res[x] = ans;
        return ans;
    };
    calc(root);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[abs(res[i] - (n - res[i]))]++;
    cout << mp.begin()->first << " " << mp.begin()->second << '\n';

    return 0;
}
