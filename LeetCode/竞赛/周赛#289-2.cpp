// 6071. 完成所有任务需要的最少轮数
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        int size = tasks.size();
        map<int, int> mp;
        for (int i = 0; i < size; i++) {
            if (mp.find(tasks[i]) == mp.end()) {
                mp.insert(make_pair(tasks[i], 1));
            }
            else {
                mp.find(tasks[i])->second++;
            }
        }
        for (auto m : mp) {
            if (m.second == 1) {
                return -1;
            }
            if (m.second % 3 == 0) {
                ans += (m.second / 3);
            }
            else {
                ans += (m.second / 3 + 1);
            }
        }
        
        return ans;
    }
};