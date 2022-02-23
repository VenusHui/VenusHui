// 278. 第一个错误的版本
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ll = 1, rr = n;
        while (ll <= rr)
        {
            int mid = (ll + rr) / 2;
            if (isBadVersion(mid) == true)
            {
                rr = mid - 1;
            }
            else
            {
                ll = mid + 1;
            }
        }
        return ll;
    }
};