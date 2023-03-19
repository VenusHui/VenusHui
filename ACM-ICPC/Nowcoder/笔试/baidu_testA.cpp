/**
 * @platform: Nowcoder_Baidu
 * @problem: baidu_testA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-13
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
        if (s.size() != 5) {
            cout << "No" << '\n';
            continue;
        }
        map<char, int> mp;
        for (auto& e : s) mp[e]++;
        if (mp['B'] == 1 && mp['a'] == 1 && mp['i'] == 1 && mp['d'] == 1 && mp['u'] == 1) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
