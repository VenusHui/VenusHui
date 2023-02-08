// 2545. 根据第 K 场考试的分数排序
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&] (vector<int>& a, vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};