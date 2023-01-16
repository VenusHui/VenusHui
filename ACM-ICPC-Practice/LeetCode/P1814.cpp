// 1814. 统计一个数组中好对子的数目
class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        function<int(int)> rev = [&] (int num) {
            if (num == 0) return 0;
            string ans;
            while (num) {
                ans += '0' + num % 10;
                num /= 10;
            }
            while (ans.size() > 0 && ans[0] == '0') ans.erase(ans.begin());
            return stoi(ans);
        };
        function<long long(int)> calc = [&] (int num) {
            long long ans = 0;
            while (num) ans += num--;
            return ans % mod;
        };
        map<int, int> mp;
        for (auto& e : nums) {
            mp[e - rev(e)]++;
        }
        long long ans = 0;
        for (auto& e : mp) {
            ans = (ans + calc(e.second - 1)) % mod;
        }
        return static_cast<int>(ans % mod);
    }
};