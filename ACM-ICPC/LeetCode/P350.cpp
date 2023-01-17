// 350. 两个数组的交集 II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, pair<int, int>> mp;
        int size1 = nums1.size(), size2 = nums2.size();
        for (auto& it : nums1) {
            mp[it].first++;
        }
        for (auto& it : nums2) {
            mp[it].second++;
        }
        for (auto& it : mp) {
            for (int i = 0; i < min(it.second.first, it.second.second); i++) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};