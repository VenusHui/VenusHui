// 154. 寻找旋转排序数组中的最小值 II
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int size = nums.size();
        int ll = 0, rr = size - 1;
        while (ll < rr)
        {
            int mid = (rr - ll) / 2 + ll;
            if (nums[mid] == nums[rr])
            {
                rr--;
            }
            else if (nums[mid] < nums[rr])
            {
                rr = mid;
            }
            else
            {
                ll = mid + 1;
            }
        }
        return nums[rr];
    }
};