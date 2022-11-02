// 1668. 最大重复子字符串
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string tmp = word;
        while (sequence.find(tmp) != string::npos) {
            tmp += word;
            ans++;
        }
        return ans;
    }
};