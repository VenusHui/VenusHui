// 2207. 字符串中最多数目的子字符串
class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long long ans1 = 0, ans2 = 0, num1 = 0, num2 = 0, n[200000] = {0}, k = 0, ans = 0;
        string p1(pattern, 0, 1), p2(pattern, 1, 1);
        string t1 = p1 + text, t2 = text + p2;
        for (int i = 0; i < text.size(); i++)
        {

            if (text[i] == pattern[1])
            {
                n[k] = num1;
                k++;
                num2++;
            }
            if (text[i] == pattern[0])
                num1++;
        }
        for (int i = 0; i < 200000; i++)
            ans += n[i];
        ans1 = ans + num2;
        ans2 = ans + num1;
        if (ans1 > ans2)
            return ans1;
        else
            return ans2;
    }
};