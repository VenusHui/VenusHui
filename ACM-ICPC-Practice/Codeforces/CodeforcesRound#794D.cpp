/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#794D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-26
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int size = s.size();
        if (size != a + b + 2 * c + 2 * d) {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> flag(size, false);
        for (int i = 0; i < size - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                flag[i + 1] = true;
                if (s[i] == 'A') {
                    a--;
                }
                else {
                    b--;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (!flag[i]) {
                if (i + 1 < size && flag[i + 1]) {
                    if (s[i] == 'A') {
                        a--;
                    }
                    else {
                        b--;
                    }
                    flag[i] = true;
                }
                else if (i + 1 < size && !flag[i]) {
                    if (s[i] == 'A' && s[i + 1] == 'B') {
                        c--;
                        flag[i] = flag[i + 1] = true;
                    }
                    else if (s[i] == 'B' && s[i + 1] == 'A') {
                        d--;
                        flag[i] = flag[i + 1] = true;
                    }
                    else if (s[i] == 'A' && s[i + 1] == 'A') {
                        a--;
                        flag[i] = true;
                    }
                    else if (s[i] == 'B' && s[i + 1] == 'B') {
                        b--;
                        flag[i] = true;
                    }
                }
                else {
                    if (s[i] == 'A') {
                        a--;
                    }
                    else {
                        b--;
                    }
                    flag[i] = true;
                }
            }
        }
        if (c < 0) {
            a += c;
            b += c;
        }
        if (d < 0) {
            a += d;
            b += d;
        }
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
