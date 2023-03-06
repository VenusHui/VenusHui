// 1599. 经营摩天轮的最大利润
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1, profit = 0, tmp = 0;
        int size = customers.size();
        int pos = 0, wait_num = 0;
        vector<int> cir(4);
        for (int i = 0; i < size; i++) {
            wait_num += customers[i];
            if (wait_num >= 4) {
                tmp += 4 * boardingCost;
                wait_num -= 4;
            }
            else {
                tmp += wait_num * boardingCost;
                wait_num = 0;
            }
            tmp -= runningCost;
            if (tmp > profit) {
                profit = tmp;
                ans = i + 1;
            }
        }
        int num = size;
        while (wait_num > 0) {
            num++;
            if (wait_num >= 4) {
                tmp += 4 * boardingCost;
                wait_num -= 4;
            }
            else {
                tmp += wait_num * boardingCost;
                wait_num = 0;
            }
            tmp -= runningCost;
            if (tmp > profit) {
                profit = tmp;
                ans = num;
            }
        }
        return ans;
    }
};