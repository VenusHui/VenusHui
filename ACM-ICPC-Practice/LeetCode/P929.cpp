// 929. 独特的电子邮件地址
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for (auto& it : emails) {
            int size = it.size();
            string tmp;
            bool atflag = false, plsflag = false;
            for (int i = 0; i < size; i++) {
                if (it[i] == '@') {
                    atflag = true;
                    tmp += it[i];
                }
                if (!atflag) {
                    if (it[i] == '+') {
                        plsflag = true;
                    }
                    if (!plsflag) {
                        if (it[i] != '.') {
                            tmp += it[i];
                        }
                    }
                }
                if (atflag) {
                    tmp += it[i];
                }
            }
            ans.insert(tmp);
        }
        return ans.size();
    }
};