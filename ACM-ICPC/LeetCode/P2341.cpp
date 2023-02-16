// 2341. 数组能形成多少数对
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans(2);
        map<int, int> mp;
        for (auto& e : nums) mp[e]++;
        for (auto& e : mp) {
            ans[0] += e.second / 2;
            ans[1] += e.second % 2;
        }
        return ans;
    }
};