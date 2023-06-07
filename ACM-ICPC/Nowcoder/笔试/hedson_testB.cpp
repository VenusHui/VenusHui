/**
 * @platform: Nowcoder
 * @problem: hedson_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-05-26
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
    vector<vector<int>> grid(n, vector<int>(n));
    int num = 1;
    pair<int, int> cnt = make_pair(0, 0), dir = make_pair(-1, 1);
    bool flag = true;
    for (int t = 1; t <= n; t++) {
        for (int k = 0; k < t; k++, cnt.first += dir.first, cnt.second += dir.second) {
            grid[cnt.first][cnt.second] = num++;
        }
        if (flag) {
            cnt.first++;
            dir = make_pair(1, -1);
            flag = false;
        }
        else {
            cnt.second++;
            dir = make_pair(-1, 1);
            flag = true;
        }
    }
    num = n * n;
    flag = false;
    cnt = make_pair(n - 1, n - 1), dir = make_pair(1, -1);
    for (int t = 1; t <= n - 1; t++) {
        for (int k = 0; k < t; k++, cnt.first += dir.first, cnt.second += dir.second) {
            grid[cnt.first][cnt.second] = num--;
        }
        if (flag) {
            cnt.second--;
            dir = make_pair(1, -1);
            flag = false;
        }
        else {
            cnt.first--;
            dir = make_pair(-1, 1);
            flag = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
