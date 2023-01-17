/**
 * @platform: AcWing
 * @problem: WeeklyContest#86A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-14
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int chest = 0, biceps = 0, back = 0;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) chest += a[i];
        if (i % 3 == 1) biceps += a[i];
        if (i % 3 == 2) back += a[i];
    }
    if (chest > biceps && chest > back) cout << "chest" << '\n';
    if (biceps > chest && biceps > back) cout << "biceps" << '\n';
    if (back > chest && back > biceps) cout << "back" << '\n';

    return 0;
}
