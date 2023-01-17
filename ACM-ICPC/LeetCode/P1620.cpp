// 1620. 网络信号最好的坐标
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int size = towers.size();
        function<int(int, int)> calc = [&] (int x, int y) {
            int ans = 0;
            for (int i = 0; i < size; i++) {
                double distance = sqrt(pow(abs(x - towers[i][0]), 2) + pow(abs(y - towers[i][1]), 2));
                if (distance <= 1.0 * radius) {
                    ans += static_cast<int>(towers[i][2] / (1 + distance));
                }
            }
            return ans;
        };
        int tmp = 0;
        vector<int> res(2);
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                if (calc(i, j) > tmp) {
                    res[0] = i;
                    res[1] = j;
                    tmp = calc(i, j);
                }
            }
        }
        return res;
    }
};