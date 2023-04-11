// 剑指 Offer 29. 顺时针打印矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int csize = matrix.size();
        if (!csize) return ans;
        int rsize = matrix[0].size();
        int num = csize * rsize;
        pair<int, int> ptr = make_pair(0, -1);
        bool row = true, add = true;
        int top = 1, right = rsize - 1, bottom = csize - 1, left = 0;
        while (num--) {
            if (row && add) {
                if (ptr.second + 1 >= right) {
                    row = false;
                    right--;
                }
                ptr.second++;
            }
            else if (!row && add) {
                if (ptr.first + 1 >= bottom) {
                    row = true;
                    add = false;
                    bottom--;
                }
                ptr.first++;
            }
            else if (row && !add) {
                if (ptr.second - 1 <= left) {
                    row = false;
                    left++;
                }
                ptr.second--;
            }
            else if (!row && !add) {
                if (ptr.first - 1 <= top) {
                    row = true;
                    add = true;
                    top++;
                }
                ptr.first--;
            }
            ans.push_back(matrix[ptr.first][ptr.second]);
        }
        return ans;
    }
};