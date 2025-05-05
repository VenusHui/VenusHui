// 23. 合并 K 个升序链表
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
// 这个写法非常的丑陋
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = nullptr;
    int k = lists.size();
    function<int()> calc = [&]() {
      int target = -1, val = 0x3f3f3f3f;
      for (int i = 0; i < k; i++) {
        if (lists[i] != nullptr && lists[i]->val < val) {
          target = i;
          val = lists[i]->val;
        }
      }
      return target;
    };
    bool flag = true;
    ListNode *prev = nullptr;
    while (true) {
      int target = calc();
      if (target == -1 || lists[target] == nullptr)
        break;
      ListNode *node = new ListNode(lists[target]->val);
      if (flag) {
        ans = node;
        prev = ans;
        flag = false;
      } else {
        prev->next = node;
        prev = prev->next;
      }
      lists[target] = lists[target]->next;
    }
    return ans;
  }
};