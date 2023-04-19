// 1023. 驼峰式匹配
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size(), psize = pattern.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int size = queries[i].size(), p = 0;
            for (int j = 0; j < size; j++) {
                if (queries[i][j] >= 'A' && queries[i][j] <= 'Z') {
                    if (queries[i][j] != pattern[p]) {
                        flag = false;
                        break;
                    }
                }
                if (queries[i][j] == pattern[p]) {
                    p++;
                }
            }
            if (flag) ans[i] = p == psize;
        }
        return ans;
    }
};