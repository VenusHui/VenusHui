// 2337. 移动片段得到字符串
class Solution {
public:
    bool canChange(string start, string target) {
        int size = start.size();
        vector<pair<char, int>> sstart, starget;
        for (int i = 0; i < size; i++) {
            if (start[i] != '_') {
                sstart.push_back(make_pair(start[i], i));
            }
            if (target[i] != '_') {
                starget.push_back(make_pair(target[i], i));
            }
        }
        if (sstart.size() != starget.size()) {
            return false;
        }
        int chsize = sstart.size();
        bool ans = true;
        for (int i = 0; i < chsize; i++) {
            if (sstart[i].first != starget[i].first) {
                ans = false;
                break;
            }
            if (sstart[i].first == 'L') {
                if (sstart[i].second < starget[i].second) {
                    ans = false;
                    break;
                }
            }
            else {
                if (sstart[i].second > starget[i].second) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};