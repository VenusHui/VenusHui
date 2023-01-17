// 6016. Excel 表中某个范围内的单元格
class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        pair<char, char> start = make_pair(s[0], s[1]);
        pair<char, char> end = make_pair(s[3], s[4]);
        vector<string> ans;
        for (int i = start.first; i <= end.first; i++)
        {
            for (int j = start.second; j <= end.second; j++)
            {
                string tmp = "";
                tmp += char(i);
                tmp += char(j);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};