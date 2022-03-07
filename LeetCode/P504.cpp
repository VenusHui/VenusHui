// 504. 7进制数
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        string ans;
        bool flag = true;
        if (num < 0)
        {
            flag = false;
            num = -1 * num;
        }
        while (num)
        {
            ans += char(num % 7 + '0');
            num /= 7;
        }
        if (!flag)
            ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};