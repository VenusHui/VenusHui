// 153. 寻找旋转排序数组中的最小值
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 二分查找
        int size = nums.size();
        int ll = 0, rr = size - 1;
        while (ll < rr)
        {
            int mid = (rr - ll) / 2 + ll;
            if (nums[mid] < nums[rr])
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

// 二分查找的特点
// 1. 顺序存储，通过下标即可找到关键字
// 2. 找到关键字之后就可以判断所要查找的值在本次查找的前面还是后面