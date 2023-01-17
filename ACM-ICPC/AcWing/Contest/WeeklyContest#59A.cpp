/**
 * @platform: AcWing
 * @problem: WeeklyContest#59A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s = 0, x = 0;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        s += res[i];
        x = min(x, s);
    }
    cout << s - x << '\n';
    
    return 0;
}
