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

// My standard binarySearch version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (isBadVersion(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};