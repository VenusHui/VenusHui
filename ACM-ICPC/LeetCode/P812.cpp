// 812. 最大三角形面积class Solution {
private:
inline double calc(vector<int> &a, vector<int> &b, vector<int> &c) {
  return abs((a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[0] * c[1] -
              b[0] * a[1] - c[0] * b[1]) /
             2.0);
}

public:
double largestTriangleArea(vector<vector<int>> &points) {
  double ans = 0;
  int size = points.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size && j != i; j++) {
      for (int k = 0; k < size && k != j && k != i; k++) {
        ans = max(ans, calc(points[i], points[j], points[k]));
      }
    }
  }
  return ans;
}
}
;