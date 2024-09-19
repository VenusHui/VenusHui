#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <unordered_set>
#include <iomanip>
typedef long long ll;
using namespace std;

// Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round) B - Prefix Removals

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int size = s.size();
        bool flag = true;
        int pos = 0;
        while (flag)
        {
            flag = false;
            for (int i = pos + 1; i < size; i++) {
                if (s[pos] == s[i]) {
                    pos++;
                    flag = true;
                    break;
                }
            }
        }
        string ans;
        for (int i = pos; i < size; i++) {
            ans += s[i];
        }
        cout << ans << '\n';
    }

    return 0;
}