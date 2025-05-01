// 剑指 Offer 25. 合并两个排序的链表
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(-1);
    ListNode *ans = head;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr && l2 != nullptr) {
        ListNode *cnt;
        if (l1->val <= l2->val) {
          cnt = new ListNode(l1->val);
          l1 = l1->next;
        } else {
          cnt = new ListNode(l2->val);
          l2 = l2->next;
        }
        head->next = cnt;
        head = head->next;
      } else if (l1 == nullptr && l2 != nullptr) {
        ListNode *cnt = new ListNode(l2->val);
        head->next = cnt;
        head = head->next;
        l2 = l2->next;
      } else if (l1 != nullptr && l2 == nullptr) {
        ListNode *cnt = new ListNode(l1->val);
        head->next = cnt;
        head = head->next;
        l1 = l1->next;
      }
    }
    return ans->next;
  }
};