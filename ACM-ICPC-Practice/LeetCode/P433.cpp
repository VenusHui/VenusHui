// 433. 最小基因变化
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        const int len = 8, ksize = 4;
        const vector<char> keys = {'A', 'C', 'G', 'T'};
        int size = bank.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < size; i++) {
            mp.insert(make_pair(bank[i], 1));
        }
        if (start == end) {
            return 0;
        }
        else if (!mp.count(end)) {
            return -1;
        }
        queue<string> q;
        q.push(start);
        int level = 1;
        while (!q.empty()) {
            int qsize = q.size();
            for (int k = 0; k < qsize; k++) {
                string cnt = q.front();
                q.pop();
                for (int i = 0; i < len; i++) {
                    for (int j = 0; j < ksize; j++) {
                        if (cnt[i] != keys[j]) {
                            string tmp = cnt;
                            tmp[i] = keys[j];
                            if (mp[tmp]) {
                                if (tmp == end) {
                                    return level;
                                }
                                q.push(tmp);
                                mp[tmp] = 0;
                            }
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
