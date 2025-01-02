/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound172C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        auto calc = [&] (int pos) {
            string ss = s.substr(pos);
            pos = 0;
            vector<string> res;
            for (int i = 0; i < ss.size(); i++) {
                if (ss[i] == '1') {
                    if (i - pos > 0) {
                        res.push_back(ss.substr(pos, i - pos));
                    }
                    pos = i;
                }
            }
            res.push_back(ss.substr(pos));
            int size = res.size();
            vector<int> score(size);
            for (int i = 0; i < size; i++) {
                for (auto& e : res[i]) {
                    if (e == '1') score[i]++;
                    else score[i]--;
                }
            }
            vector<int> prefix(size + 1);
            if (prefix[size] >= k) {
                return 2;
            }

            for (int i = 0; i < size; i++) {
                prefix[i + 1] = prefix[i] + score[i];
            }

            int fscore = 0;
            int d = 0x3f3f3f3f;
            for (int i = 0; i < size; i++) {
                fscore += (i + 1) * score[i];
                if (fscore + (i + 2) * (prefix[size] - prefix[i + 1]) >= k) {
                    d = min(d, i + 2);
                }
            }
            return d;
        };

        int znum = 0, onum = 0;
        int res = 0x3f3f3f3f;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '0') {
                znum++;
            }
            else {
                onum++;
                if (onum > znum) {
                    res = min(res, calc(i));
                }
            }
        }

        if (res == 0x3f3f3f3f) {
            cout << "-1" << '\n';
        }
        else {
            cout << res << '\n';
        }
    }

    return 0;
}
