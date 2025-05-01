// 857. 雇佣 K 名工人的最低成本
class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    int n = quality.size();
    vector<int> index(n, 0);
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&](int &a, int &b) {
      return wage[a] * quality[b] < wage[b] * quality[a];
    });
    priority_queue<int, vector<int>, less<int>> q;
    double totquality = 0;
    for (int i = 0; i < k - 1; i++) {
      totquality += quality[index[i]];
      q.push(quality[index[i]]);
    }
    double ans = 1e9 + 1;
    for (int i = k - 1; i < n; i++) {
      int idx = index[i];
      totquality += quality[idx];
      q.push(quality[idx]);
      double tmp = (static_cast<double>(wage[idx]) / quality[idx]) * totquality;
      ans = min(ans, tmp);
      totquality -= q.top();
      q.pop();
    }
    return ans;
  }
};