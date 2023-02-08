// 1604. 警告一小时内使用相同员工卡大于等于三次的人
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int size = keyName.size();
        map<string, vector<int>> mp;
        for (int i = 0; i < size; i++) {
            mp[keyName[i]].push_back(stoi(keyTime[i].substr(0, 2)) * 60 + stoi(keyTime[i].substr(3, 2)));
        }
        vector<string> ans;
        for (auto& e : mp) {
            sort(e.second.begin(), e.second.end());
            int n = e.second.size();
            for (int i = 0; i < n - 2; i++) {
                if (e.second[i + 2] - e.second[i] <= 60) {
                    ans.push_back(e.first);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};