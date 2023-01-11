/**
 * @platform: AcWing
 * @problem: P793 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string mul(string s, int num) {
    string ans;
    int t = 0, i = s.size() - 1;
    while (t || i >= 0) {
        if (i >= 0) t += (s[i] - '0') * num;
        ans += t % 10 + '0';
        t /= 10, i--;
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1;
    int num;
    cin >> s1 >> num;
    cout << mul(s1, num) << '\n';

    return 0;
}
