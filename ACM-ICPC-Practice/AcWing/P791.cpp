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

string add(string num1, string num2)
{
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || carry)
    {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int temp = x + y + carry;
        res += '0' + temp % 10;
        carry = temp / 10;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
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
