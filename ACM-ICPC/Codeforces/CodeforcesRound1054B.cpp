/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1054B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-10-01
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                int diff = abs(a[i - 1] - a[i]);
                nums.push_back(diff);
            }
        }
        int ans = -0x3f3f3f3f;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
