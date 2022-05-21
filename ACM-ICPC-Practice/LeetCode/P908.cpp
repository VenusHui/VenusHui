// 908. 最小差值 I
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        int nmax = -1, nmin = 1e4 + 1;
        for (int i = 0; i < size; i++) {
            nmin = min(nmin, nums[i]);
            nmax = max(nmax, nums[i]);
        }
        return nmax - nmin >= 2 * k ? nmax - nmin - 2 * k : 0;
    }
};