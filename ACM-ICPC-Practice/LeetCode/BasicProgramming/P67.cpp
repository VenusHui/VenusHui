// 67. 二进制求和
class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size(), bsize = b.size();
        int length;
        if (asize > bsize) {
            length = asize;
            for (int i = 0; i < asize - bsize; i++) {
                b.insert(b.begin(), '0');
            }
        }
        else {
            length = bsize;
            for (int i = 0; i < bsize - asize; i++) {
                a.insert(a.begin(), '0');
            }
        }
        string ans;
        bool flag = false;
        for (int i = length - 1; i >= 0; i--) {
            if (a[i] == '1' && b[i] == '1') {
                ans.insert(ans.begin(), char('0' + flag));
                flag = true;
            }
            else if (a[i] == '0' && b[i] == '0') {
                ans.insert(ans.begin(), char('0' + flag));
                flag = false;
            }
            else {
                if (flag) {
                    ans.insert(ans.begin(), char('0'));
                }
                else {
                    ans.insert(ans.begin(), char('1'));
                }
            }
        }
        if (flag) {
            ans.insert(ans.begin(), char('1'));
        }
        return ans;
    }
};