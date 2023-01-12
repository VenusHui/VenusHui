// 141. 环形链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        while (head != nullptr) {
            mp[head]++;
            if (mp[head] > 1) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};