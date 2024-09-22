/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound#798B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-06
 */
#include <iostream>
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
using namespace std;;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            pq.push(i + 1);
        }
        if (n == 1) {
            cout << "-1" << '\n';
            continue;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (pq.top() != q[i]) {
                ans[i] = pq.top();
                pq.pop();
            }
            else {
                if (i == n - 1) {
                    ans[i] = pq.top();
                    swap(ans[i], ans[i - 1]);
                    break;
                }
                int tmp = pq.top();
                pq.pop();
                ans[i] = pq.top();
                pq.pop();
                pq.push(tmp);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}

