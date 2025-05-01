// 剑指 Offer 24. 反转链表
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
  ListNode *reverseList(ListNode *head) {
    ListNode *tmp = nullptr;
    while (head) {
      ListNode *node = new ListNode(head->val);
      node->next = tmp;
      tmp = node;
      head = head->next;
    }
    return tmp;
  }
};