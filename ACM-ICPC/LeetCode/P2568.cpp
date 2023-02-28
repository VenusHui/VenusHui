// 2568. 最小无法得到的或值
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int size = nums.size();
        map<int, int> mp;
        for (auto& e : nums) mp[e]++;
        for (int i = 0; i <= 31; i++) {
            if (mp[(1 << i)] == 0) {
                return (1 << i);
            }
        }
        return 0;
    }
};