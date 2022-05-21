// 739. 每日温度

// 暴力 TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& res) {
        int size = res.size();
        vector<int> ans(size);
        for (int i = 0; i < size - 1; i++) {
            bool flag = false;
            int tmp = 0;
            for (int j = i + 1; j < size; j++) {
                tmp++;
                if (res[j] > res[i]) {
                    break;
                }
                if (j == size - 1) {
                    tmp = 0;
                }
            }
            ans[i] = tmp;
        }
        return ans;
    }
};

// 单调栈 AC
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& res) {
        int size = res.size();
        vector<int> ans(size);
        stack<pair<int, int> > s;
        for (int i = 0; i < size; i++) {
            if (s.empty() || res[i] <= s.top().second) {
                s.push(make_pair(i, res[i]));
            }
            else {
                ans[s.top().first] = i - s.top().first;
                s.pop();
                i--;
            }
        }
        while (s.empty()) {
            ans[s.top().first] = 0;
        }
        return ans;
    }
};