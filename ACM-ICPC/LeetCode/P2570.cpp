// 2570. 合并两个二维数组 - 求和法
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for (auto& e : nums1) mp[e[0]] += e[1];
        for (auto& e : nums2) mp[e[0]] += e[1];
        vector<vector<int>> ans;
        for (auto& e : mp) ans.push_back({e.first, e.second});
        return ans;
    }
};