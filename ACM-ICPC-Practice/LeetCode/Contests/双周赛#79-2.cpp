// 2284. 最多单词数的发件人
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int size = senders.size();
        vector<int> res(size);
        for (int i = 0; i < size; i++) {
            int tmp = 1;
            for (auto& it : messages[i]) {
                if (it == ' ') {
                    tmp++;
                }
            }
            res[i] = tmp;
        }
        map<string, int> mp;
        for (int i = 0; i < size; i++) {
            if (mp.find(senders[i]) == mp.end()) {
                mp.insert(make_pair(senders[i], res[i]));
            }
            else {
                mp.find(senders[i])->second += res[i];
            }
        }
        pair<string, int> ans = *mp.begin();
        for (auto& it : mp) {
            if (it.second > ans.second) {
                ans = it;
            }
            else if (it.second == ans.second) {
                if (it.first > ans.first) {
                    ans = it;
                }
            }
        }
        return ans.first;
    }
};