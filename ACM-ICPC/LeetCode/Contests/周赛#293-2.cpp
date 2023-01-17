// 6064. 不含特殊楼层的最大连续楼层数
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int size = special.size();
        int ans = special[0] - bottom;
        for (int i = 1; i < size; i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        ans = max(ans, top - special[size - 1]);
        return ans;
    }
};