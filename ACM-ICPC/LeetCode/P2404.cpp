// 2404. 出现最频繁的偶数元素
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for (auto& e : nums) mp[e]++;
        pair<int, int> tmp = make_pair(-1, 0);
        for (auto& e : mp) {
            if (e.first % 2 == 0) {
                if (e.second > tmp.second) {
                    tmp = e;
                }
            }
        }
        return tmp.first;
    }
};