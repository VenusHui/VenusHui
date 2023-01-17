// 2442. 反转之后不同整数的数目
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        function<int(int)> calc = [&] (int a) {
            vector<int> res;
            while (a) {
                res.push_back(a % 10);
                a /= 10;
            }
            reverse(res.begin(), res.end());
            int num = 0, rsize = res.size();
            for (int i = 0; i < rsize; i++) {
                num += res[i] * static_cast<int>(pow(10, i));
            }
            return num;
        };
        set<int> st;
        for (auto& it : nums) {
            st.insert(it);
            st.insert(calc(it));
        }
        int ans = st.size();
        return ans;
    }
};