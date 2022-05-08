// 442. 数组中重复的数据
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> res(n + 1, 0);
        for (int i = 0; i < n; i++) {
            res[nums[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (res[i] == 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};