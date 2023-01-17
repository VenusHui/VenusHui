// 面试题 01.05. 一次编辑
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second) {
            return true;
        }
        if (first.size() > second.size()) {
            swap(first, second);
        }
        int fsize = first.size(), ssize = second.size();
        if (fsize == ssize) {
            int dif = 0;
            for (int i = 0; i < fsize; i++) {
                if (first[i] != second[i]) {
                    dif++;
                }
            }
            if (dif > 1) {
                return false;
            }
            return true;
        }
        else if (fsize + 1 == ssize) {
            bool flag = true;
            int f = 0, s = 0;
            while (f < fsize && s < ssize) {
                if (first[f] != second[s]) {
                    if (flag) {
                        s++;
                        flag = false;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                f++;
                s++;
            }
            return true;
        }
        return false;
    }
};