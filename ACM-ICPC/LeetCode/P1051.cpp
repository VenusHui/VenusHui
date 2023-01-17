// 1051. 高度检查器
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        int ans = 0, size = heights.size();
        for (int i = 0; i < size; i++) {
            if (heights[i] != tmp[i]) {
                ans++;
            }
        }
        return ans;
    }
};