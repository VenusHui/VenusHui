class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int tmp = i, num = i;
            bool flag = true;
            while (tmp) {
                int mod = tmp % 10;
                if (mod == 0) {
                    tmp /= 10;
                    flag = false;
                    break;
                }
                if (num % mod != 0) {
                    flag = false;
                    break;
                }
                tmp /= 10;
            }
            if (flag) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};