// 2492. 两个城市间路径的最小分数
class Solution {
private:
public:
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> edge(n + 1);
    int size = roads.size();
    for (int i = 0; i < size; i++) {
      edge[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
      edge[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
    }
    vector<bool> vis;
    function<void(int)> dfs = [&](int s) {
      if (vis[s]) {
        return;
      }
      vis[s] = true;
      for (auto &i : edge[s]) {
        dfs(i.first);
      }
    };
    vis = vector<bool>(n + 1, false);
    dfs(1);
    vector<bool> state1 = vis;
    vis = vector<bool>(n + 1, false);
    dfs(n);
    vector<bool> state2 = vis;
    int ans = 1e9 + 1;
    for (int i = 0; i < size; i++) {
      if (state1[roads[i][0]] && state2[roads[i][0]]) {
        ans = min(ans, roads[i][2]);
      }
    }
    if (ans > 1e9) {
      return -1;
    }
    return ans;
  }
};