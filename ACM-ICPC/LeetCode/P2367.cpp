// 2367. 算术三元组的数目
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (auto& e : nums) mp[e]++;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i] + diff] && mp[nums[i] + 2 * diff]) ans++;
        }
        return ans;
    }
};