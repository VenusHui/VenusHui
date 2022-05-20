// 6034. 数组的三角和
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size(), ans = 0;
        vector<int> tmp, cnt;
        cnt = nums;
        for (int t = 0; t < size - 1; t++) {
            int k = cnt.size();
            for (int i = 0; i < k - 1; i++) {
                tmp.push_back((cnt[i] + cnt[i + 1]) % 10);
            }
            cnt = tmp;
            tmp.clear();
        }
        return cnt[0];
    }
};