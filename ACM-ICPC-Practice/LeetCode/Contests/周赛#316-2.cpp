// 2447. 最大公因数等于 K 的子数组数目
class Solution {
private:
    inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == k) {
                ans++;
            }
            int tmp = nums[i];
            for (int j = i + 1; j < size; j++) {
                if (gcd(tmp, nums[j]) == k) {
                    ans++;
                }
                tmp = gcd(tmp, nums[j]);
            }
        }
        return ans;
    }
};