/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-12
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
        for (int i = 0; i < n; i++) {
            int size;
            string s;
            cin >> size >> s;
            int tmp = 0;
            for (int j = 0; j < size; j++) {
                if (s[j] == 'U') {
                    tmp--;
                }
                else {
                    tmp++;
                }
            }
            a[i] = (a[i] + tmp + 100) % 10;
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
