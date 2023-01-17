// 2418. 按身高排序
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int size = heights.size();
        vector<pair<int, string>> res(size);
        for (int i = 0; i < size; i++) {
            res[i] = make_pair(heights[i], names[i]);
        }
        sort(res.begin(), res.end(), [&] (pair<int, string>& a, pair<int, string>& b) {
            return a.first > b.first;
        });
        vector<string> ans(size);
        for (int i = 0; i < size; i++) {
            ans[i] = res[i].second;
        }
        return ans;
    }
};