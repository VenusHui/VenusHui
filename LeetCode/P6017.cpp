// 6017. 向数组中追加 K 个整数

// 暴力 TLE
class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        long long ans = 0;
        set<int> res;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            res.insert(nums[i]);
        set<int>::iterator it = res.begin();
        int tmp = 1;
        while (k)
        {
            if (tmp == *it)
            {
                tmp++;
                it++;
                if (it == res.end())
                    break;
            }
            else
            {
                ans += tmp;
                tmp++;
                k--;
            }
        }
        while (k--)
            ans += tmp++;
        return ans;
    }
};
