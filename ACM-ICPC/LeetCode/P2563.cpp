// 2563. 统计公平数对的数目
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
            int loper = 0, roper = 0;
            int l = i + 1, r = size - 1;
            while (l < r) {
                int m = l + r >> 1;
                if (nums[m] < lower - nums[i]) l = m + 1;
                else r = m;
            }
            loper = l;
            l = i + 1, r = size - 1;
            while (l < r) {
                int m = l + r + 1 >> 1;
                if (nums[m] <= upper - nums[i]) l = m;
                else r = m - 1;
            }
            roper = r;
            if (loper >= 0 && loper < size && roper >= 0 && roper < size && nums[i] + nums[loper] >= lower && nums[i] + nums[roper] <= upper) ans += roper - loper + 1;
        }
        return ans;
    }
};