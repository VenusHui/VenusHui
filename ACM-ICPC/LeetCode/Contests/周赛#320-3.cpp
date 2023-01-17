// 6243. 到达首都的最少油耗
class Solution {
typedef long long ll;
public:
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> mp(n + 1);
        for (int i = 0; i < n; i++) {
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> vis(n + 1, false);
        vector<int> visn(n + 1, 1);
        ll ans = 0;
        function<ll(int)> dfs = [&] (int cnt) {
            if (vis[cnt]) {
                return 0;
            }
            vis[cnt] = true;
            for (auto& i : mp[cnt]) {
                visn[cnt] += dfs(i);
            }
            if (cnt) {
                if (visn[cnt] % seats == 0) {
                    ans += visn[cnt] / seats;
                }
                else {
                    ans += visn[cnt] / seats + 1;
                }
            }
            return visn[cnt];
        };
        dfs(0);
        return ans;
    }
};