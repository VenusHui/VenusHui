/**
 * @platform: AcWing
 * @problem: P799 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-12
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
    int ans = 0;
    set<int> st;
    for (int i = 0, j = 0; j < n; j++) {
        while (st.find(a[j]) != st.end()) {
            st.erase(a[i++]);
        }
        st.insert(a[j]);
        ans = max(ans, static_cast<int>(st.size()));
    }
    cout << ans << '\n';

    return 0;
}
