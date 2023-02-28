// 2363. 合并相似的物品
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int, int> mp;
        for (auto& e : items1) mp[e[0]] += e[1];
        for (auto& e : items2) mp[e[0]] += e[1];
        for (auto& e : mp) ans.push_back({e.first, e.second});
        return ans;
    }
};