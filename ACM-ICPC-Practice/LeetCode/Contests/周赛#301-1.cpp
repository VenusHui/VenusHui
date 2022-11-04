// 2335. 装满杯子需要的最短总时长
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (amount[0] + amount[1] + amount[2] != 0) {
            int a = amount[0], b = amount[1], c = amount[2];
            int mmax = max(a, max(b, c));
            int mmin = min(a, min(b, c));
            int mmid = a + b + c - mmin - mmax;
            if (mmax > 0 && mmid > 0) {
                mmax--;
                mmid--;
            }
            else if (mmax > 0 && mmid == 0) {
                mmax--;
            }
            ans++;
            amount[0] = mmax;
            amount[1] = mmid;
            amount[2] = mmin;
        }
        return ans;
    }
};