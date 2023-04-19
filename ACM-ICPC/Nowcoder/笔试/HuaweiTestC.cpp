/**
 * @platform: Huawei
 * @problem: HuaweiTestC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 0, x;
    vector<int> a;
    while (cin >> x) {
        a.push_back(x);
        n++;
    }
    vector<int> base(n);
    base[0] = a[0], base[n - 1] = a[n - 1];
    for (int i = 0; i < n; i++) {
        if (a[i] >= base[0]) base[i] = max(base[i], base[0]);
        else break;
    }
    for (int i = n - 1; i >= n; i--) {
        if (a[i] >= base[n - 1]) base[i] = max(base[i], base[0]);
        else break;
    }
    vector<int> b(n);
    for (int i = 1; i < n - 1; i++) {
        b[i] = a[i] - base[i];
    }
    vector<bool> track(n, false);
    for (int i = 1; i < n - 1; i++) {
        if (b[i] > b[i - 1] && b[i] > b[i + 1]) track[i] = true;
        if (b[i] > b[i - 1] && b[i] == b[i + 1]) {
            int j = i + 1;
            while (b[j] != b[i]) {
                j++;
            }
            if (b[j] < b[i]) track[i] = true;
            i = j - 1;
        }
    }
    vector<int> ans(n);
    for (int i = 1; i < n - 1; i++) {
        if (track[i]) {
            ans[i] += b[i];
            continue;
        }
        int l = -1, r = -1;
        for (int j = i; j >= 0; j--) {
            if (track[j]) {
                l = j;
                break;
            }
        }
        for (int j = i; j < n; j++) {
            if (track[j]) {
                r = j;
                break;
            }
        }
        if (b[i - 1] > b[i + 1] && b[i + 1] < b[i]) {
            ans[l] += b[i];
        }
        else if (b[i - 1] < b[i + 1] && b[i - 1] < b[i]) {
            ans[r] += b[i];
        }
        else if (b[i - 1] >= b[i] && b[i + 1] >= b[i]) {
            if (b[l] < b[r]) {
                ans[r] += b[i];
            }
            else if (b[l] >= b[r]) {
                ans[l] += b[i];
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (track[i]) {
            if (flag) {
                cout << ans[i];
                flag = false;
            }
            else {
                cout << " " << ans[i];
            }
        }
    }
    cout << '\n';
    return 0;
}
