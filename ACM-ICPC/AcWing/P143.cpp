/**
 * @platform: AcWing
 * @problem: P143 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// 使用 vector 会在 3e7 数据量时 MLE(over 64MB)，将 vector 改为 int[] 即可通过
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    const int maxn = 2;
    vector<vector<int>> trie(1, vector<int>(maxn));
    function<void(int)> insert = [&] (int s) {
        int pos = 0;
        for (int i = 30; i >= 0; i--) {
            int b = s >> i & 1;
            if (trie[pos][b] == 0) {
                trie[pos][b] = trie.size();
                trie.push_back(vector<int>(maxn));
            }
            pos = trie[pos][b];
        }
    };
    function<int(int)> query = [&] (int s) {
        int pos = 0, ans = 0;
        for (int i = 30; i >= 0; i--) {
            int b = s >> i & 1;
            if (trie[pos][!b] != 0) {
                pos = trie[pos][!b];
                ans += 1 << i;
            }
            else {
                pos = trie[pos][b];
            }
        }
        return ans;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) insert(a[i]);
    for (int i = 0; i < n; i++) ans = max(ans, query(a[i]));
    cout << ans << '\n';

    return 0;
}
