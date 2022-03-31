// 2217. 找到指定长度的回文数
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& qr, int length) {
        bool odd = length % 2;
        int len = (length + 1) / 2;
        vector<long long> index(length + 1);
        index[0] = 1;
        for (int i = 1; i <= length; i++) {
            index[i] = index[i - 1] * 10;
        }
        vector<long long> ans;
        int size = qr.size();
        for (int i = 0; i < size; i++) {
            int q = qr[i] - 1;
            bool flag = true;
            vector<int> nums(length + 1);
            for (int l = 1, r = length; l <= len && flag; l++, r--) {
                int tmp;
                if (l == 1) {
                    tmp = q / index[len - l] + 1;
                }
                else {
                    tmp = q / index[len - l];
                }
                if (tmp > 9) {
                    flag = false;
                    break;
                }
                nums[l] = nums[r] = tmp;
                q %= index[len - l];
            }
            if (!flag) {
                ans.push_back(-1);
            }
            else {
                long long num = 0;
                for (int j = 1; j <= length; j++) {
                    num  = num * 10 + nums[j];
                }
                ans.push_back(num);
            }
        }
        return ans;
    }
};