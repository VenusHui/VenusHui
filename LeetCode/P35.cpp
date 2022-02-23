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