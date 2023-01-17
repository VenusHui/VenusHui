/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50A 
 * @version: ContestVersion
 * @author: VenusHui
 * @date: 2022-05-21
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (res[i] > res[i - 1] * k || res[i] * k < res[i - 1]) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
