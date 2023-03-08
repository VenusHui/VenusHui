// 剑指 Offer 17. 打印从1到最大的n位数
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        bool loop = true;
        int num = 1;
        while (loop) {
            int tmp = num, len = 0;
            while (tmp) {
                tmp /= 10;
                len++;
            }
            if (len <= n) ans.push_back(num++);
            else loop = false;
        }
        return ans;
    }
};