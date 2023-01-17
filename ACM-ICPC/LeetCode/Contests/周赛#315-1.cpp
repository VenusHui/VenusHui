// 2441. 与对应负数同时存在的最大正整数
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        int ans = -1;
        for (auto& it : nums) {
            if (it > 0 && mp[it] != 0 && mp[-1 * it] != 0) {
                ans = max(ans, it);
            }
        }
        return ans;
    }
};