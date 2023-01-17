// 896. 单调数列
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int index = 0;
        int flag = -1;
        int size = nums.size();
        if (size == 2 || size == 1)
            return true;
        while (flag == -1 && index + 1 < size)
        {
            if (nums[index] > nums[index + 1])
                flag = true; // 递减
            else if (nums[index] < nums[index + 1])
                flag = false; // 递增
            else if (nums[index] == nums[index + 1])
                index++;
        }
        for (index; index < size - 1; index++)
        {
            if (nums[index] >= nums[index + 1] && flag == true) // 递减
                continue;
            if (nums[index] <= nums[index + 1] && flag == false) // 递增
                continue;
            return false;
        }
        return true;
    }
};