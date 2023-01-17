// 2470. 最小公倍数为 K 的子数组数目
class Solution {
private:
    inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            int tmp = nums[i];
            for (int j = i; j < size; j++) {
                tmp = lcm(tmp, nums[j]);
                if (tmp == k) {
                    ans++;
                }
                else if (tmp > k) {
                    break;
                }
            }
        }
        return ans;
    }
};