// 剑指 Offer 22. 链表中倒数第k个节点
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
  ListNode *getKthFromEnd(ListNode *head, int k) {
    vector<ListNode *> res;
    while (head) {
      res.push_back(head);
      head = head->next;
    }
    return res[res.size() - k];
  }
};