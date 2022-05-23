// 2279. 装满石头的背包的最大数量
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int size = capacity.size();;
        vector<int> tmp(size);
        for (int i = 0; i < size; i++) {
            tmp[i] = capacity[i] - rocks[i];
        }
        sort(tmp.begin(), tmp.end());
        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (additionalRocks - tmp[i] >= 0) {
                additionalRocks -= tmp[i];
                ans++;
            }
            else {
                break;
            }
        }
        return ans;
    }
};