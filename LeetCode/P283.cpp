// 283. 移动零
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 双指针
        int size = nums.size();
        if (size == 1)
            return;
        int left = 0, right = 0;
        while (right < size)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
