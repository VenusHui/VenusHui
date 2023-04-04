/**
 * @platform: Little Red Book
 * @problem: LittleRedBook_testA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 26;
    int n;
    cin >> n;
    string s, ans;
    cin >> s;
    for (auto& e : s) {
        int idx = e - 'a';
        idx = (idx - 3 + maxn) % maxn;
        ans += char('a' + idx);
    }
    cout << ans << '\n';

    return 0;
}
