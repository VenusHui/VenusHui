// 剑指 Offer 18. 删除链表的节点
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* pre = nullptr, *cnt = head;
        while (cnt) {
            if (cnt->val == val) {
                pre->next = cnt->next;
            }
            pre = cnt, cnt = cnt->next;
        }
        return head;
    }
};