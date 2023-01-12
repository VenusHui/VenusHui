// 21. 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* ans = head;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 != nullptr && list2 != nullptr) {
                ListNode* cnt;
                if (list1->val <= list2->val) {
                    cnt = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else {
                    cnt = new ListNode(list2->val);
                    list2 = list2->next;
                }
                head->next = cnt;
                head = head->next;
            }
            else if (list1 == nullptr && list2 != nullptr) {
                ListNode* cnt = new ListNode(list2->val);
                head->next = cnt;
                head = head->next;
                list2 = list2->next;
            }
            else if (list1 != nullptr && list2 == nullptr) {
                ListNode* cnt = new ListNode(list1->val);
                head->next = cnt;
                head = head->next;
                list1 = list1->next;
            }
        }
        return ans->next;
    }
};