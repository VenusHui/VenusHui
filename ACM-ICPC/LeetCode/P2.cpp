// 2. 两数相加
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = nullptr, *head = nullptr;
    int t = 0;
    while (t || l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr)
        t += l1->val, l1 = l1->next;
      if (l2 != nullptr)
        t += l2->val, l2 = l2->next;
      if (head == nullptr) {
        head = new ListNode(t % 10);
        ans = head;
      } else {
        ListNode *node = new ListNode(t % 10);
        head->next = node;
        head = node;
      }
      t /= 10;
    }
    return ans;
  }
};