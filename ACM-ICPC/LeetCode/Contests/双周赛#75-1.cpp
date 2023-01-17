// 2220. 转换数字的最少位翻转次数
class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s, g;
        while (start) {
           s += char('0' + start % 2);
            start /= 2;
        }
        reverse(s.begin(), s.end());
        while (goal) {
            g += char('0' + goal % 2);
            goal /= 2;
        }
        reverse(g.begin(), g.end());
        int ssize = s.size(), gsize = g.size();
        if (ssize < g.size()) {
            for (int i = ssize; i < gsize; i++) {
                s.insert(s.begin(), '0');
            }
        }
        else {
            for (int i = gsize; i < ssize; i++) {
                g.insert(g.begin(), '0');
            }
        }
        int ans = 0, size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] != g[i]) {
                ans++;
            }
        }
        return ans;
    }
};