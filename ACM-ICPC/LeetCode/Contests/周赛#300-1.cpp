// 2325. 解密消息
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> res(26, '0'), tmp(26, '0');
        unordered_map<char, int> mp;
        int size = key.size(), pos = 0;
        for (int i = 0; i < size; i++) {
            if (key[i] == ' ') {
                continue;
            }
            if (mp[key[i]] == 0) {
                res[pos] = key[i];
                pos++;
                mp[key[i]]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            tmp[res[i] - 'a'] = char('a' + i);
        }
        for (auto& it : message) {
            if (it != ' ') {
                it = tmp[it - 'a'];            
            }
        }
        return message;
    }
};