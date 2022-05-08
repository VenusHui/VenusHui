/************************* 
 *  nowcoder小白月赛49-2
 *  Writer: VenusHui
 *  Date: 2022-05-06
**************************/
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
#include <functional>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> res(n, vector<bool>(201, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                cin >> num;
                res[i][num] = true;
            }
        }
        vector<bool> flag(n, true);
        for (int i = 0; i < m; i++) {
            int b, ans = 0;
            cin >> b;
            for (int j = 0; j < n; j++) {
                if (flag[j]) {
                    if (!res[j][b]) {
                        flag[j] = false;
                    }
                    else{
                        ans++;
                    }
                }
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
