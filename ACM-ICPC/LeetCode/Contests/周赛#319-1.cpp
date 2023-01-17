// 6233. 温度转换
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        ans.push_back(1.0 * celsius + 273.15);
        ans.push_back(1.0 * celsius * 1.80 + 32.00);
        return ans;
    }
};