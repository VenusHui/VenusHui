// 459. 重复的子字符串
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool ans = false;
        int size = s.size();
        string sub;
        for (int i = 0; i < size / 2; i++)
        {
            sub += s[i];
            int ssize = sub.size();
            if (size % ssize == 0)
            {
                string res;
                int re = size  / ssize;
                for (int j = 0; j < re; j++)
                    res += sub;
                bool flag = true;
                for (int j = 0; j < size; j++)
                {
                    if (res[j] != s[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};