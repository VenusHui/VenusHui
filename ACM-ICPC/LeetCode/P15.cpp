// 15. 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size(), i = 0;
        while (i < size) {
            while (i - 1 >= 0  && i + 1 < size && nums[i - 1] == nums[i]) i++;
            int l = i + 1, r = size - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                    do {
                        l++;
                    } while (l < size && nums[l - 1] == nums[l]);
                    do {
                        r--;
                    } while (r >= 0 && nums[r + 1] == nums[r]);
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    do {
                        r--;
                    } while (r >= 0 && nums[r + 1] == nums[r]);
                }
                else if (nums[i] + nums[l] + nums[r] < 0) {
                    do {
                        l++;
                    } while (l < size && nums[l - 1] == nums[l]);
                }
            }
            i++;
        }
        return ans;
    }
};