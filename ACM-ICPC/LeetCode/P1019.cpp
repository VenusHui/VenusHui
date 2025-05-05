// 1019. 链表中的下一个更大节点
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
  vector<int> nextLargerNodes(ListNode *head) {
    stack<int> stk;
    vector<int> ans, a;
    while (head) {
      a.push_back(head->val);
      head = head->next;
    }
    reverse(a.begin(), a.end());
    for (auto &e : a) {
      while (!stk.empty() && stk.top() <= e)
        stk.pop();
      ans.push_back(stk.empty() ? 0 : stk.top());
      stk.push(e);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

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
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> ans;
    stack<pair<int, int>> stk;
    int idx = -1;
    while (head) {
      idx++, ans.push_back(0);
      while (!stk.empty() && head->val > stk.top().first) {
        ans[stk.top().second] = head->val;
        stk.pop();
      }
      stk.push(make_pair(head->val, idx));
      head = head->next;
    }
    return ans;
  }
};