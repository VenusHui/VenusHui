// 48. 旋转图像

// 辅助矩阵 空间复杂度O(N * N)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int> > res;
        for (int j = 0; j < size; j++) {
            vector<int> tmp(size);
            for (int i = 0; i < size; i++) {
                tmp[size - i - 1] = matrix[i][j];
            }
            res.push_back(tmp);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = res[i][j];
            }
        }
        return;
    }
};

// 翻转 O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // 水平轴翻转
        for (int j = 0; j < size; j++) {
            int l = 0, r = size - 1;
            while (l < r) {
                swap(matrix[l][j], matrix[r][j]);
                l++;
                r--;
            }
        }

        // 主对角线翻转
        // 矩阵关于主对角线翻转的方法：
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};