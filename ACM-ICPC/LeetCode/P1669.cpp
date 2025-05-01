// 1669. 合并两个链表
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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *node = list1, *left = nullptr, *right = nullptr;
    int res = 0;
    while (node) {
      if (res == a - 1)
        left = node;
      if (res == b + 1)
        right = node;
      res++;
      node = node->next;
    }
    left->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = right;
    return list1;
  }
};