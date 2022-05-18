// 5234. 移除字母异位词后的结果数组
class Solution {
private:
    inline bool calc(string& a, string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int size = a.size();
        map<char, int> mpa, mpb;
        for (int i = 0; i < size; i++) {
            mpa[a[i]]++;
            mpb[b[i]]++;
        }
        return mpa == mpb;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int size = words.size();
        vector<bool> flag(size, true);
        for (int i = 1; i < size; i++) {
            if (calc(words[i - 1], words[i])) {
                flag[i] = false;
            }
        }
        for (int i = 0; i < size; i++) {
            if (flag[i]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};