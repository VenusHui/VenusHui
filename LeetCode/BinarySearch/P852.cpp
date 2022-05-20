// 852. 山脉数组的峰顶索引
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int l = 0, r = size - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] <= arr[m + 1]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
};