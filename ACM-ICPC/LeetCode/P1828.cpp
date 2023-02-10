// 1828. 统计一个圆中点的数目
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int res = 0;
            for (auto& e : points) {
                if ((q[0] - e[0]) * (q[0] - e[0]) + (q[1] - e[1]) * (q[1] - e[1]) <= q[2] * q[2]) res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};