// 1041. 困于环中的机器人
class Solution {
public:
    bool isRobotBounded(string instructions) {
        const vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        pair<int, int> cor = make_pair(0, 0), dir = dirs[0];
        for (auto& e : instructions) {
            if (e == 'G') {
                cor.first += dir.first;
                cor.second += dir.second;
            }
            if (e == 'L') {
                for (int i = 0; i < 4; i++) {
                    if (dirs[i] == dir) {
                        dir = dirs[(i - 1 + 4) % 4];
                        break;
                    }
                }
            }
            if (e == 'R') {
                for (int i = 0; i < 4; i++) {
                    if (dirs[i] == dir) {
                        dir = dirs[(i + 1 + 4) % 4];
                        break;
                    }
                }
            }
        }
        if (dir == dirs[0] && cor != make_pair(0, 0)) return false;
        return true;
    }
};