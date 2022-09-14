// 667. 优美的排列 II
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for (int i = 1; i <= n; i++) {
            res[i - 1] = i;
        }
        int l = 0, r = n - 1;
        vector<int> ans;
        while (k > 2) {
            ans.push_back(res[l++]);
            ans.push_back(res[r--]);
            k -= 2;
        }
        if (k == 2) {
            swap(res[l + 1], res[l + 2]);
        }
        for (int i = l; i <= r; i++) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};