/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#830A 
 * @version: Contest Version (Unsolved)
 * @author: VenusHui
 * @date: 2022-10-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

inline int calc(vector<int> nums) {
    int size = nums.size(), ans = nums[0];
    for (int i = 0; i < size; i++) {
        ans = gcd(ans, nums[i]);
    }
    return ans;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (calc(a) == 1) {
            cout << "0" << '\n';
            continue;
        }
        vector<vector<int>> res;
        for (int i = 1; i <= n; i++) {

        }
        int ans = 1 << 30;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> tmp = a;
            tmp[i] = gcd(a[i], i + 1);
            if (calc(tmp) == 1) {
                ans = min(ans, n - i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
