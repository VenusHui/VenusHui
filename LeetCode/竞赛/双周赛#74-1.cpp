// 6020. 将数组划分成相等数对
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<pair<int, int> > res;
        int size = nums.size();
        for (int i = 0 ; i < size; i++) {
            bool flag = false;;
            int rsize = res.size();
            for (int j = 0; j < rsize; j++) {
                if (res[j].first == nums[i]) {
                    res[j].second++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                res.push_back(make_pair(nums[i], 1));
            }
        }
        int rsize = res.size();
        for (int i = 0; i < rsize; i++) {
            if (res[i].second % 2 != 0) {
               return false;
            }
        }
        return true;
    }
};