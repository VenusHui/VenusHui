// 6022. 将数组和减半的最少操作次数
class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans = 0;
        double sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        double aim = sum / 2;
        priority_queue<double> q;
        for (int i = 0; i < size; i++) {
            q.push(static_cast<double>(nums[i]));
        }
        
        while (aim > 0) {
            double tmp = q.top();
            aim -= (tmp / 2);
            q.pop();
            q.push(tmp / 2);
            ans++;
        }
        return ans;
    }
};