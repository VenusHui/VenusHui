// 6031. 找出数组中的所有 K 近邻下标
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> res;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == key)
            {
                for (int j = i - k >= 0 ? i - k : 0; j <= i + k && j < size; j++)
                {
                    res.insert(j);
                }
            }
        }
        vector<int> ans;
        for (auto it = res.begin(); it != res.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};