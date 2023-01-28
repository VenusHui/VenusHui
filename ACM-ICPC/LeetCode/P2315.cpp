// 2315. 统计星号
class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool flag = true;
        for (auto& e : s) {
            if (flag && e == '*') ans++;
            if (e == '|') flag = !flag;
        }
        return ans;
    }
};