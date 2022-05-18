/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#791(Div.2) C. Rooks Defenders
 * @version: Tutorial
 * @author: VenusHui
 * @date: 2022-05-18
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> row(n + 1), col(n + 1);
    vector<int> rflag(n + 1), cflag(n + 1);
    function<int(vector<int>&, int)> ask = [&] (vector<int>& tree, int x) {
        int ans = 0;
        for (; x; x -= x & -x) {
            ans += tree[x];
        }
        return ans;
    };
    function<void(vector<int>&, int, int)> add = [&] (vector<int>& tree, int x, int y) {
        for (; x <= n; x += x & -x) {
            tree[x] += y;
        }
    };
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            rflag[x]++;
            cflag[y]++;
            if (rflag[x] == 1) {
                add(row, x, 1);
            }
            if (cflag[y] == 1) {
                add(col, y, 1);
            }
        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;
            rflag[x]--;
            cflag[y]--;
            if (rflag[x] == 0) {
                add(row, x, -1);
            }
            if (cflag[y] == 0) {
                add(col, y, -1);
            }
        }
        else {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (ask(row, x2) - ask(row, x1 - 1) == x2 - x1 + 1 || ask(col, y2) - ask(col, y1 - 1) == y2 - y1 + 1) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
