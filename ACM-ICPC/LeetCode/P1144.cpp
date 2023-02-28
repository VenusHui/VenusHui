// 1144. 递减元素使数组呈锯齿状
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int size = nums.size();
        int ans = 0, tmp = 0;
        vector<int> res = nums;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                while (i - 1 >= 0 && res[i] <= res[i - 1]) res[i - 1]--, tmp++;
                while (i + 1 < size && res[i] <= res[i + 1]) res[i + 1]--, tmp++;
            }
        }
        ans = tmp, tmp = 0, res = nums;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 1) {
                while (i - 1 >= 0 && res[i] <= res[i - 1]) res[i - 1]--, tmp++;
                while (i + 1 < size && res[i] <= res[i + 1]) res[i + 1]--, tmp++;
            }
        }
        ans = min(ans, tmp);
        return ans;
    }
};