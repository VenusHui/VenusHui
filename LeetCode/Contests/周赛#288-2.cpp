// 6038. 向表达式添加括号后的最小结果
class Solution {
public:
    int calc(string s) {
        int ans = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            ans *= 10;
            ans += (s[i] - '0');
        }
        return ans;
    }
    string minimizeResult(string expression) {
        string ans;
        int size = expression.size(), flag = 0;
        for (int i = 0; i < size; i++) {
            if (expression[i] == '+') {
                flag = i;
                break;
            }
        }
        int dic = INT_MAX;
        for (int i = 0; i < flag; i++) {
            string s = expression;
            s.insert(s.begin() + i, '(');
            for (int j = flag + 3; j <= size + 1; j++) {
                string t = s;
                t.insert(t.begin() + j, ')');
                int n = t.size();
                string tmp;
                vector<int> c;
                for (int k = 0; k < n; k++) {
                    if (t[k] >= '0' && t[k] <= '9') {
                        tmp += t[k];
                    }
                    else {
                        if (tmp.size() == 0) {
                            c.push_back(1);
                        }
                        else {
                            c.push_back(calc(tmp));
                            tmp.clear();
                        }
                    }
                }
                if (tmp.size() == 0) {
                    c.push_back(1);
                }
                else {
                    c.push_back(calc(tmp));
                    tmp.clear();
                }
                if (c[0] * (c[1] + c[2]) * c[3] < dic) {
                    dic = c[0] * (c[1] + c[2]) * c[3];
                    ans = t;
                }
            }
        }
        return ans;
    }
};