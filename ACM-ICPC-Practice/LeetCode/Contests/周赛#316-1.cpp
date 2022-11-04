// 2446. 判断两个事件是否存在冲突
class Solution {
private:
    int calc(string s) {
        int hour = stoi(s.substr(0, 2));
        int mins = stoi(s.substr(3, 4));
        return hour * 60 + mins;
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1 = calc(event1[0]), e1 = calc(event1[1]);
        int s2 = calc(event2[0]), e2 = calc(event2[1]);
        if (s2 > e1 || s1 > e2) {
            return false;
        }
        return true;
    }
};