/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound129C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-23
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
        int n, k = 0;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> at = a, bt = b;
        sort(at.begin(), at.end());
        sort(bt.begin(), bt.end());
        vector<pair<int, int>> ans;
        vector<bool> flag(n, false);
        bool ansflag = true;
        for (int i = 0; i < n; i++) {
            if (k > 10000) {
                ansflag = false;
                break;
            }
            if (flag[i]) {
                continue;
            }
            if (at[i] != a[i]) {
                for (int j = 0; j < n; j++) {
                    if (a[j] == at[i] && b[j] == bt[i] && !flag[j]) {
                        k++;
                        ans.push_back(make_pair(i, j));
                        flag[i] = true;
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                        i = 0;
                        break;
                    }
                }
            }
            else if (at[i] == a[i] && bt[i] == b[i]) {
                flag[i] = true;
            }
            else if (at[i] == a[i] && bt[i] != b[i]) {
                for (int j = 0; j < n; j++) {
                    if (a[j] == at[i] && b[j] == bt[i] && !flag[j]) {
                        k++;
                        ans.push_back(make_pair(i, j));
                        flag[i] = true;
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                        i = 0;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!flag[i]) {
                ansflag = false;
                break;
            }
        }
        if (!ansflag) {
            cout << "-1" << '\n';
        }
        else {
            cout << k << '\n';
            int size = ans.size();
            for (int i = 0; i < size; i++) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
            }
        }
    }

    return 0;
}
