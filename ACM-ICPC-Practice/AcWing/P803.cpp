/**
 * @platform: AcWing
 * @problem: P803 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-13
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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    function<vector<pair<int, int>>(vector<pair<int, int>>&)> merge = [&] (vector<pair<int, int>>& segs) {
        vector<pair<int, int>> ans;
        sort(segs.begin(), segs.end());
        pair<int, int> interval = make_pair(INT_MIN, INT_MIN);
        for (auto& seg : segs) {
            if (interval.second < seg.first) {
                if (interval.first != INT_MIN) ans.push_back(interval);
                interval = seg;
            }
            else {
                interval.second = max(interval.second, seg.second);
            }
        }
        if (interval.first != INT_MIN) ans.push_back(interval);
        return ans;
    };
    cout << merge(a).size() << '\n';

    return 0;
}
