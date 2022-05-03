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

// Codeforces Round #786 (Div. 3) B. Dictionary

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, idx = 1;
    cin >> t;
    vector<vector<int>> res(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == i) {
                continue;
            }
            res[i][j] = idx++;
        }
    }
    while (t--) {
        string s;
        cin >> s;
        cout << res[s[0] - 'a'][s[1] - 'a'] << '\n';
    }
    
    return 0;
}
