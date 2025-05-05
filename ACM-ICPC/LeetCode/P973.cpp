// 973. 最接近原点的 K 个点
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> ans;
    vector<pair<int, pair<int, int>>> s;
    int size = points.size();
    for (int i = 0; i < size; i++) {
      int tmp = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
      s.push_back(make_pair(tmp, make_pair(points[i][0], points[i][1])));
    }
    sort(s.begin(), s.end());
    vector<pair<int, pair<int, int>>>::iterator it = s.begin();
    while (k--) {
      vector<int> tmp(2);
      tmp[0] = it->second.first;
      tmp[1] = it->second.second;
      ans.push_back(tmp);
      it++;
    }
    return ans;
  }
};