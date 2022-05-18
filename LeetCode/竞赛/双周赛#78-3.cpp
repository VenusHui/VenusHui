// 6068. 毯子覆盖的最多白色砖块数
class Solution {
private:
    vector<int> pre;
    inline int calc(vector<vector<int>>& res, int s, int k) {
        int size = res.size();
        int l = s, r = size - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (res[m][1] <= k) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        int ans = pre[l];
        if (s > 0) {
            ans -= pre[s - 1];
        }
        if (l + 1 < size) {
            if (res[l + 1][0] <= k) {
                ans += k - res[l + 1][0] + 1;
            }
        }     
        return ans;
    }
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int size = tiles.size(), ans = 0;
        sort(tiles.begin(), tiles.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        pre.resize(size);
        pre[0] = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < size; i++) {
            pre[i] = pre[i - 1] + tiles[i][1] - tiles[i][0] + 1;
        }
        for (int i = 0; i < size; i++) {
            ans = max(ans, calc(tiles, i, tiles[i][0] + carpetLen - 1));
        }
        return ans;
    }
};