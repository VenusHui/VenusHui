// 1823. 找出游戏的获胜者
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (k + ans - 1) % i + 1;
        }
        return ans;
    }
};