// 1798. 你能构造出连续值的最大数目
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans = 1;
        sort(coins.begin(), coins.end());
        for (auto& e : coins) {
            if (e > ans) break;
            ans += e;
        }
        return ans;
    }
};