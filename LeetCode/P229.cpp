// 229. 求众数 II
// 方法一：暴力模拟：排序+枚举
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int count = 0, pre = nums.at(0), n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums.at(i) == pre)
            {
                count++;
            }
            else
            {
                if (count > (n / 3))
                {
                    ans.push_back(pre);
                }
                count = 1;
                pre = nums.at(i);
            }
        }
        if (count > (n / 3))
        {
            ans.push_back(pre);
        }
        return ans;
    }
};

// 方法二：摩尔投票法
