// 2326. 螺旋矩阵 IV
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        pair<int, int> pos = make_pair(0, 0);
        int top = -1, bot = n, left = -1, right = m;
        int dir = 0;
        if (m == 1) {
            dir = 1;
        }
        function<void()> calc = [&] () {
            if (dir == 0) {
                pos.second++;
                if (pos.second + 1 == right) {
                    dir = (dir + 1) % 4;
                    top++;
                }
            }
            else if (dir == 1) {
                pos.first++;
                if (pos.first + 1 == bot) {
                    dir = (dir + 1) % 4;
                    right--;
                }
            }
            else if (dir == 2) {
                pos.second--;
                if (pos.second - 1 == left) {
                    dir = (dir + 1) % 4;
                    bot--;
                }
            }
            else if (dir == 3) {
                pos.first--;
                if (pos.first - 1 == top) {
                    dir = (dir + 1) % 4;
                    left++;
                }
            }
        };
        while (head) {
            ans[pos.first][pos.second] = head->val;
            calc();
            head = head->next;
        }
        return ans;
    }
};