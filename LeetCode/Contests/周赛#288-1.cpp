// 6037. 按奇偶性交换后的最大数字
class Solution {
public:
    int largestInteger(int num) {
        string ans;
        int res = num;
        vector<int> a, b;
        while (num) {
            int tmp = num % 10;
            if (tmp % 2 == 1) {
                a.push_back(tmp);
            }
            else {
                b.push_back(tmp);
            }
            num /= 10;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int asize = a.size(), bsize = b.size(), apos = 0, bpos = 0;
        while (res) {
            int tmp = res % 10;
            if (tmp % 2 == 1) {
                ans.insert(ans.begin(), char('0' + a[apos]));
                apos++;
            }
            else {
                ans.insert(ans.begin(), char('0' + b[bpos]));
                bpos++;
            }
            res /= 10;
        }
        return stoi(ans);
    }
};