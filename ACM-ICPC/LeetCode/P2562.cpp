// 2562. 找出数组的串联值
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int size = nums.size();
        for (int i = 0; i < size / 2; i++) {
            string tmp = to_string(nums[i]) + to_string(nums[size - i - 1]);
            ans += stoi(tmp);
        }
        if (size % 2 != 0) ans += nums[size / 2];
        return ans;
    }
};