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

// 走不出的迷宫

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> maze(h + 1, vector<char>(w + 1, '#'));
    vector<vector<int>> dp(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (maze[i][j] == '.' && (dp[i - 1][j] != 0 || dp[i][j - 1] != 0)) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
            else if (dp[i - 1][j] == 0 && dp[i][j - 1] == 0 && i * j != 1) {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
