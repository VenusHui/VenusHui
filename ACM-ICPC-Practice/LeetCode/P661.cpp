// 661. 图片平滑器
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int> > ans;
        int row = img.size(), col = img[0].size();
        for (int i = 0; i < row; i++) {
            vector<int> res(col);
            for (int j = 0; j < col; j++) {
                int tmp = 0, num = 0;
                for (int k = max(0, i - 1); k < min(i + 2, row); k++) {
                    for (int t = max(0, j - 1); t < min(j + 2, col); t++) {
                        num++;
                        tmp += img[k][t];
                    }
                }
                tmp /= num;
                res[j] = static_cast<int>(tmp);
            }
            ans.push_back(res);
        }
        return ans;
    }
};