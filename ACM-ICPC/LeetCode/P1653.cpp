// 1653. 使字符串平衡的最少删除次数
class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size();
        int preb = 0, ans = 0x3f3f3f3f;
        vector<int> sufa(size + 1, 0);
        for (int i = size - 1; i >= 0; i--) {
            sufa[i] = sufa[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        for (int i = 0; i < size; i++) {
            if (s[i] == 'b') {
                ans = min(ans, preb + sufa[i + 1]);
                preb++;
            }
        }
        ans = min(ans, preb);
        if (ans == 0x3f3f3f3f) return 0;
        return ans;
    }
};