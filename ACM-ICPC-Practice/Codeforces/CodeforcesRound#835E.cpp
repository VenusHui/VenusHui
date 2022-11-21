/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835E 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-21
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll merge(vector<ll>& a, int l, int mid, int r) {
    ll count = 0;
    int p1 = l;
    int p2 = mid + 1;
    int i = 0;
    vector<ll> help(r - l + 1);
    while (p1 <= mid && p2 <= r) {
        count += a[p1] > a[p2] ? (mid - p1 + 1) : 0;
        help[i++] = a[p1] <= a[p2] ? a[p1++] : a[p2++];
    }
    while (p1 <= mid)
        help[i++] = a[p1++];
    while (p2 <= r)
        help[i++] = a[p2++];
    for (i = 0; i < help.size(); i++)
        a[l + i] = help[i];
    return count;
}
ll mergeSort(vector<ll>& a, int l, int r) {
    if (l == r)
        return 0;
    int mid = l + (r - l) / 2;
    return mergeSort(a, l, mid) + mergeSort(a, mid + 1, r) + merge(a, l, mid, r);
}
ll SmallSum(vector<ll>& a) {
    if (a.size() < 2)
        return 0;
    return mergeSort(a, 0, a.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> tmp = a;
        ll ans = SmallSum(tmp);
        tmp = a;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == 0) {
                tmp[i] = (tmp[i] + 1) % 2;
                ans = max(ans, SmallSum(tmp));
                break;
            }
        }
        tmp = a;
        for (int i = n - 1; i >= 0; i--) {
            if (tmp[i] == 1) {
                tmp[i] = (tmp[i] + 1) % 2;
                ans = max(ans, SmallSum(tmp));
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
