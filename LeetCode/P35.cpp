// 35. 搜索插入位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ll = 0, rr = nums.size() - 1;
        while (ll <= rr)
        {
            int mid = (rr - ll) / 2 + ll;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                rr = mid - 1;
            }
            else if (nums[mid] < target)
            {
                ll = mid + 1;
            }
        }
    }
};

// another version
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return l;
    }
};