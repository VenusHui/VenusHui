// 1626. 无矛盾的最佳球队
class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    int n = scores.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = make_pair(scores[i], ages[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        if (a[j].second <= a[i].second)
          dp[i] = max(dp[i], dp[j]);
      }
      dp[i] += a[i].first;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};