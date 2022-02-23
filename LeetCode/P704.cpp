// 704. 二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ll = 0, rr = nums.size() - 1;
        while (ll <= rr)
        {
            int mid = (ll + rr) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            else if (nums.at(mid) < target)
            {
                ll = mid + 1;
            }
            else if (nums.at(mid) > target)
            {
                rr = mid - 1;
            }
        }
        return -1;
    }
};