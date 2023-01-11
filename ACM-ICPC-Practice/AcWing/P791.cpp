/**
 * @platform: AcWing
 * @problem: P791 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string add(string s1, string s2) {
    string ans;
    int t = 0, i = s1.size() - 1, j = s2.size() - 1;
    while (t || i >= 0 || j >= 0) {
        t += i >= 0 ? s1[i] - '0' : 0;
        t += j >= 0 ? s2[j] - '0' : 0;
        ans += t % 10 + '0';
        t /= 10;
        i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2) << '\n';

    return 0;
}
