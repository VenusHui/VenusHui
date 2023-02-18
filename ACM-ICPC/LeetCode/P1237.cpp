// 1237. 找出给定方程的正整数解
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        const int maxn = 1000;
        vector<vector<int>> ans;
        for (int i = 1; i <= maxn; i++) {
            for (int j = 1; j <= maxn; j++) {
                if (customfunction.f(i, j) == z) ans.push_back({i, j});
            }
        }
        return ans;
    }
};