// 5203. 统计可以提取的工件
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans = 0;
        vector<vector<bool> > mp;
        vector<bool> tmp;
        for (int i = 0; i < n; i++)
            tmp.push_back(false);
        for (int i = 0; i < n; i++)
            mp.push_back(tmp);
        int dsize = dig.size();
        for (int i = 0; i < dsize; i++)
            mp[dig[i][0]][dig[i][1]] = true;
        int asize = artifacts.size();
        for (int i = 0; i < asize; i++)
        {
            bool flag = true;
            for (int r = artifacts[i][0]; r <= artifacts[i][2]; r++)
            {
                for (int c = artifacts[i][1]; c <= artifacts[i][3]; c++)
                {
                    if (mp[r][c] == false)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};