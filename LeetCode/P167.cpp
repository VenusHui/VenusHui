// 167. 两数之和 II - 输入有序数组
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int size = numbers.size();
        int left = 0, right = size - 1;
        vector<int> ans(2);
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                ans[0] = left + 1, ans[1] = right + 1;
                break;
            }
            else if (numbers[left] + numbers[right] > target)
                right--;
            else if (numbers[left] + numbers[right] < target)
                left++;
        }
        return ans;
    }
};