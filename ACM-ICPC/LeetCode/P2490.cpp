// 2490. 回环句
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.size();
        vector<char> res;
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                res.push_back(sentence[i]);
                res.push_back(sentence[0]);
            }
            if (sentence[i] == ' ') {
                res.push_back(sentence[i - 1]);
                res.push_back(sentence[i + 1]);
            }
        }
        bool flag = true;
        int rsize = res.size();
        for (int i = 0; i < rsize; i += 2) {
            if (res[i] != res[i + 1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};