/**
 * @platform: AcWing
 * @problem: P843 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-31
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> place(n + 1);
    function<bool(int, int)> check = [&] (int x, int y) {
        int i = 1;
        while (i < x) {
            if (place[i] == y || abs(x - i) == abs(place[i] - y)) return false;
            i++;
        }
        return true;
    };
    function<void()> print = [&] () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j != place[i]) cout << ".";
                else cout << "Q";
            }
            cout << '\n';
        }
        cout << '\n';
    };
    function<void(int)> dfs = [&] (int row) {
        if (row > n) {
            print();
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (check(row, i)) {
                place[row] = i;
                dfs(row + 1);
            }
        }
    };
    dfs(1);

    return 0;
}
