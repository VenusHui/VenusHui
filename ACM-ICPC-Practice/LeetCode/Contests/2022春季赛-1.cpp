// 1. 宝石补给
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        int size = gem.size(), n = operations.size();
        for (int i = 0; i < n; i++) {
            int x = operations[i][0], y = operations[i][1];
            int num = gem[x] / 2;
            gem[x] -= num, gem[y] += num;
        }
        sort(gem.begin(), gem.end());
        return gem[size - 1] - gem[0];
    }
};