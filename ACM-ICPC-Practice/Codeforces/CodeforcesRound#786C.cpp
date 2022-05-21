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

// Codeforces Round #786 (Div. 3) C. Infinite Replacement

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        string s, t;
        cin >> s >> t;
        ll ssize = s.size(), tsize = t.size();
        if (tsize == 1 && t[0] == 'a') {
            cout << "1" << '\n';
            continue;
        }
        else if (tsize > 1 && t.find('a') != string::npos) {
            cout << "-1" << '\n';
            continue;
        }
        cout << (1 << ssize) << '\n';
    }
    
    return 0;
}
