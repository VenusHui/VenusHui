// 6039. K 次增加后的最大乘积
class Solution {
private:
    long long mod = 1e9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long ans = 1;
        int size = nums.size();
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < size; i++) {
            q.push(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            int tmp = q.top();
            q.pop();
            tmp++;
            q.push(tmp);
        }
        for (int i = 0; i < size; i++) {
            long long tmp = q.top();
            q.pop();
            ans = (ans * tmp) % mod;
        }
        
        return ans % mod;
    }
};