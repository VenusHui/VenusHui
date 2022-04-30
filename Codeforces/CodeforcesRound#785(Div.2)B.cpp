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

// Codeforces Round #785 (Div. 2) B. B. A Perfectly Balanced String?

inline bool calc(string& s, int std, int l, int r) {
    set<char> st;
    for (int i = l; i <= r; i++) {
        st.insert(s[i]);
    }
    int ans = st.size();
    if (ans == std) {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int size = s.size();
        set<char> st;
        vector<vector<int>> res(26);
        for (int i = 0; i < size; i++) {
            st.insert(s[i]);
            res[s[i] - 'a'].push_back(i);
        }
        int std = st.size();
        bool ans = true;
        for (int i = 0; i < 26; i++) {
            int rsize = res[i].size();
            for (int j = 0; j < rsize - 1; j++) {
                if (!calc(s, std, res[i][j], res[i][j + 1])) {
                    ans = false;
                    break;
                }
            }
            if (!ans) {
                break;
            }
        }
        if (ans) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
