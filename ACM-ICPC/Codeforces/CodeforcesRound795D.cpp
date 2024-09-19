/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#795D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-31
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<pair<int, int>> tree(n + 1);
        function<void(int, int)> update = [&] (int x, int y) {
            for (; x <= n; x += x & -x) {
                tree[x].second += y;
                tree[x].first = a[x];
                for (int i = 1; i < x & -x; i <<= 1) {
                    tree[x].first = max(tree[x].first, tree[x - i].first);
                }
            }
        };
        function<int(int, int)> query = [&] (int x, int y) {
            int ans = 0;
            while (y >= x) {
                ans = max(ans, a[y--]);
                while (y - y & -y >= x) {
                    ans = max(ans, tree[y].first);
                    y -= y & -y;
                }
            }
            return ans;
        };
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            update(i, a[i]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (query(i - i & -i + 1, i) < tree[i].second) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
