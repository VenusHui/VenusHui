// 5268. 找出两数组的不同
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        int size1 = nums1.size(), size2 = nums2.size();
        set<int> s1;
        set<int> s2;
        for (int i = 0; i < size1; i++) {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < size2; i++) {
            s2.insert(nums2[i]);
        }
        vector<int> tmp;
        set<int>::iterator it;
        for (it = s1.begin(); it != s1.end(); it++) {
            if (s2.find(*it) == s2.end()) {
                tmp.push_back(*it);
            }
        }
        ans.push_back(tmp);
        tmp.clear();
        for (it = s2.begin(); it != s2.end(); it++) {
            if (s1.find(*it) == s1.end()) {
                tmp.push_back(*it);
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};