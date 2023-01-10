/**
 * @platform: AcWing
 * @problem: P788 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-09
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    function<ll(int, int)> merge_sort = [&] (int l, int r) {
        if (l == r) {
            return 0LL;
        }
        int mid = l + r >> 1;
        ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
        int i = l, j = mid + 1;
        vector<int> tmp;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                tmp.push_back(a[i++]);
            }
            else {
                tmp.push_back(a[j++]);
                ans += mid - i + 1;
            }
        }
        while (i <= mid) {
            tmp.push_back(a[i++]);
        }
        while (j <= r) {
            tmp.push_back(a[j++]);
        }
        for (i = l, j = 0; i <= r; i++, j++) {
            a[i] = tmp[j];
        }
        return ans;
    };
    cout << merge_sort(0, n - 1) << '\n';

    return 0;
}
