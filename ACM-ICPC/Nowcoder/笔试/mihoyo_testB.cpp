/**
 * @platform: Nowcoder_mihoyo
 * @problem: mihoyo_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-19
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
        string s, t;
        cin >> s >> t;
        function<string(string)> calc = [&] (string str) {
            int size = str.size();
            int l = -1, r = size;
            vector<bool> vis(r, true);
            while (l < r) {
                do l++; while (str[l] != 'm');
                do r--; while (str[r] != 'y');
                bool flag = false;
                int m = l;
                for (; m < r; m++) {
                    if (str[m] == 'h') {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    vis[l] = false, vis[r] = false, vis[m] = false;
                }
            }
            string tmp;
            for (int i = 0; i < size; i++) {
                if (vis[i]) tmp += str[i];
            }
            return tmp;
        };
        s = calc(s), t = calc(t);
        vector<int> sv(26), tv(26);
        for (auto& e : s) sv[e - 'a']++;
        for (auto& e : t) tv[e - 'a']++;
        bool ans = true;
        for (int i = 0; i < 26; i++) {
            if (sv[i] != tv[i]) {
                ans = false;
                break;
            }
        }
        function<string(string)> calcc = [&] (string str) {
            int size = str.size();
            vector<bool> vis(size, true);
            for (int i = 0; i < size; i++) {
                if (str[i] == 'm' || str[i] == 'h' || str[i] == 'y') vis[i] = false;
            }
            string tmp;
            for (int i = 0; i < size; i++) {
                if (vis[i]) tmp += str[i];
            }
            return tmp;
        };
        s = calcc(s), t = calcc(t);
        if (ans && s == t) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}
