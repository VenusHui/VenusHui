// 5299. 找到一个数字的 K 美丽值
class Solution {
private:
    bool calc(string s, int l, int k) {
        int num = stoi(s), size = s.size();
        int cnt = 0;
        for (int i = l; i < l + k; i++) {
            cnt = cnt * 10 + (s[i] - '0');
        }
        if (cnt == 0) {
            return false;
        }
        if (num % cnt == 0) {
            return true;
        }
        return false;
    }
public:
    int divisorSubstrings(int num, int k) {
        int res = num;
        string s;
        while (res) {
            s += char(res % 10 + '0');
            res /= 10;
        }
        reverse(s.begin(), s.end());
        int size = s.size(), ans = 0;
        for (int i = 0; i < size - k + 1; i++) {
            if (calc(s, i, k)) {
                ans++;
            }
        }
        return ans;
    }
};