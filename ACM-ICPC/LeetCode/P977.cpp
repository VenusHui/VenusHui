// 977. 有序数组的平方
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i;
        vector<int> ans;
        for (i = 0; i < static_cast<int>(nums.size()) - 1; i++)
        {
            if (abs(nums[i]) < abs(nums[i + 1]))
            {
                break;
            }
        }
        int j = i + 1;
        while (true)
        {
            if (i == -1 && j == static_cast<int>(nums.size()))
            {
                break;
            }
            if (i == -1)
            {
                ans.push_back(static_cast<int>(pow(nums[j], 2)));
                j++;
            }
            else if (j == static_cast<int>(nums.size()))
            {
                ans.push_back(static_cast<int>(pow(nums[i], 2)));
                i--;
            }
            else if (abs(nums[i]) < abs(nums[j]))
            {
                ans.push_back(static_cast<int>(pow(nums[i], 2)));
                i--;
            }
            else
            {
                ans.push_back(static_cast<int>(pow(nums[j], 2)));
                j++;
            }
        }
        return ans;
    }
};