// 2300. 咒语和药水的成功对数
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) {
            a[i] = spells[i];
        }
        for (int i = 0; i < m; i++) {
            b[i] = potions[i];
        }
        vector<int> ans(n);
        sort(b.begin(), b.end());
        b.insert(b.begin(), 0);
        for (int i = 0; i < n; i++) {
            long long tar;
            if (success % a[i] == 0) {
                tar = success / a[i];
            }
            else {
                tar = success / a[i] + 1;
            }
            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (b[mid] < tar) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            ans[i] = m - l;
        }
        return ans;
    }
};