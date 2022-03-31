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
#include <iomanip>
typedef long long ll;
using namespace std;

// Codeforces Round #780 (Div. 3) C. Get an Even String

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        int size = s.size();
        map<char, int> mp;
        for (int i = 0; i < size; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp.insert(make_pair(s[i], 1));
            }
            else {
                ans += (mp.size() - 1);
                mp.clear();
            }
        }
        ans += mp.size();
        cout << ans << '\n';
    }

    return 0;
}
