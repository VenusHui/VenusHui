// 2295. 替换数组中的元素
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size(), m = operations.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < m; i++) {
            int tmp = mp[operations[i][0]];
            mp.erase(mp.find(operations[i][0]));
            mp[operations[i][1]] = tmp;
        }
        vector<pair<int, int>> ans;
        for (auto& it : mp) {
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i].first;
        }
        return nums;
    }
};