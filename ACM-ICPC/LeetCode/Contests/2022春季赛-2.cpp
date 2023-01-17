// 2. 烹饪料理
class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int ans = -1;
        int msize = materials.size(), csize = cookbooks.size();
        for (int i = 0; i < pow(2, csize); i++) { // 所有的情况
            int bao = 0, mei = 0, choose = i;
            vector<int> tmp = materials;
            for (int j = 0; j < csize; j++) { // 每种情况下菜的不同组合
                bool flag = false;
                if (choose % 2) {
                    bool flag = true;
                    vector<int> res = tmp;
                    for (int k = 0; k < msize; k++) {
                        if (res[k] - cookbooks[j][k] >= 0) {
                            res[k] -= cookbooks[j][k];
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        bao += attribute[j][1];
                        mei += attribute[j][0];
                        tmp = res;
                    }
                }
                choose /= 2;
                
            }
            if (bao >= limit) {
                ans = max(ans, mei);
            }
        }
        return ans;
    }
};