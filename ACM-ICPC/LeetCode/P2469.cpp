// 2469. 温度转换
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans(2);
        ans = {celsius + 273.15, celsius * 1.8 + 32};
        return ans;
    }
};