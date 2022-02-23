// 917. 仅仅反转字母
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int size = s.size(), lnum = 0;
        vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                tmp.push_back(s[i]);
                lnum++;
            }
        }
        for (int i = size; i >= 0; i--)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = tmp[--lnum];
            }
        }
        return s;
    }
};