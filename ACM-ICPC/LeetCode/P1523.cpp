// 1523. 在区间范围内统计奇数数目
class Solution
{
public:
    int countOdds(int low, int high)
    {
        int ans = (high - low) / 2;
        if (low % 2 == 1 || high % 2 == 1)
        {
            ans++;
        }
        return ans;
    }
};