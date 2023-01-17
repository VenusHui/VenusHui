// 828. 统计子串中的唯一字符
class Solution {
public:
    int uniqueLetterString(string s) {
        const int maxn = 26;
        int size = s.size();
        vector<vector<int>> res(maxn, vector<int>(1, -1));
        for (int i = 0; i < size; i++) {
            res[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < maxn; i++) {
            res[i].push_back(size);
        }
        int ans = 0;
        for (int i = 0; i < maxn; i++) {
            int isize = res[i].size();
            for (int j = 0; j < isize - 2; j++) {
                ans += (res[i][j + 2] - res[i][j + 1]) * (res[i][j + 1] - res[i][j]);
            }
        }
        return ans;
    }
};