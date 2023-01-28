// 203. 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        while (node != nullptr) {
            if (node->next != nullptr && node->next->val == val) {
                node->next = node->next->next;
                continue;
            }
            node = node->next;
        }
        return head == nullptr || head->val != val ? head : head->next;
    }
};