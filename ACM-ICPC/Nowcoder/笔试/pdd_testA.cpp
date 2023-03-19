/**
 * @platform: Nowcoder-PDD
 * @problem: pdd_testA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, ans;
    cin >> s;
    vector<pair<string, int>> mp;
    int size = s.size(), num = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }
        else {
            for (int j = 0; j < num; j++) {
                ans += s[i];
            }
            num = 0;
        }
    }
    cout << ans << '\n';

    return 0;
}
