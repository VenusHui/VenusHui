// 1. 气温变化趋势
class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int size = temperatureA.size();
        int ans = 0, tmp = 0;
        for (int i = 1; i < size; i++) {
            if (temperatureA[i] > temperatureA[i - 1] && temperatureB[i] > temperatureB[i - 1] ||
                temperatureA[i] < temperatureA[i - 1] && temperatureB[i] < temperatureB[i - 1] || 
                temperatureA[i] == temperatureA[i - 1] && temperatureB[i] == temperatureB[i - 1]) {
                tmp++;
            }
            else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        ans = max(ans, tmp);
        return ans;
    }
};