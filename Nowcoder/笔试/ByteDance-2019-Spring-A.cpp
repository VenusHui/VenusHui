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
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

// 字节跳动2019春招研发编程题部分 A

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, ans;
        cin >> s;
        for (int i = 0; i < s.size();) {
            if (i + 2 < s.size() && s[i] == s[i + 1] && s[i] == s[i + 2]) {
                s.erase(s.begin() + i);
            }
            else if (i + 3 < s.size() && s[i] == s[i + 1] && s[i + 2] == s[i + 3]) {
                s.erase(s.begin() + i + 2);
            }
            else {
                i++;
            }
        }
        cout << s << '\n';
    }
    
    return 0;
}