class Solution {
public:
  inline int dijsktra(vector<vector<pair<int, int>>> edge, int n, int s,
                      int t) {
    vector<int> dist(n + 1, (1 << 30) + 1);
    dist[s] = 0;
    // pair<int, int>的小根堆，第一个int代表边权，第二个int代表点的编号
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
      int x = q.top().second;
      if (x == t || dist[x] > 1 << 30) {
        break;
      }
      q.pop();
      for (auto it : edge[x]) {
        if (dist[x] + it.second < dist[it.first]) {
          dist[it.first] = dist[x] + it.second;
          q.push(make_pair(dist[it.first], it.first));
        }
      }
    }
    if (dist[t] > 1 << 30) {
      return -1;
    }
    return dist[t];
  }
  int minCost(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < edges.size(); i++) {
      e[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
      e[edges[i][1]].push_back(make_pair(edges[i][0], 2 * edges[i][2]));
    }
    return dijsktra(e, n, 0, n - 1);
  }
};
