// 2195. 向数组中追加 K 个整数

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

// AC
class Solution {
public:
    long long calc (int& k, long long l, long long r) {
        if (l > r) {
            return 0;
        }
        r = min(r, l + k - 1);
        k -= (r - l + 1);
        return 1LL * (l + r) * (r - l + 1) / 2;
    }
    
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        ans += calc(k, 1, nums[0] - 1);
        for (int i = 0; i < size - 1; i++) {
            ans += calc(k, nums[i] + 1, nums[i + 1] - 1);
        }
        int maxNum = 2e9 + 1;
        ans += calc(k, nums[size - 1] + 1, maxNum);
        return ans;
    }
};
