/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#823C 
 * @version: Contest Version UnSolved (Wa Pretest3)
 * @author: VenusHui
 * @date: 2022-09-25
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
        string s;
        cin >> s;
        int size = s.size();
        string ans;
        for (int i = 0; i < size; i++) {
            ans += "9";
        }
        vector<int> res(size);
        int maxn = 9;
        for (int i = 0; i < size; i++) {
            res[i] = s[i] - '0';
            if (i > 0 && res[i] < res[i - 1]) {
                maxn = min(maxn, res[i]);
            }
        }
        for (int minn = 0; minn <= maxn; minn++) {
            vector<int> tmp = res;
            bool flag = true;
            for (int i = 0; i < size; i++) {
                if (tmp[i] > minn) {
                    tmp[i] = min(tmp[i] + 1, 9);
                }
            }
            sort(tmp.begin(), tmp.end());
            string str;
            for (int i = 0; i < size; i++) {
                str.push_back(char(tmp[i] + '0'));
            }
            ans = min(ans, str);
        }
        cout << ans << '\n';
    }

    return 0;
}
