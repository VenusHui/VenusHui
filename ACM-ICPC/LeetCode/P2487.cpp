// 2487. 从链表中移除节点
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
    ListNode* removeNodes(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        int size = res.size();
        int maxn = res[size - 1];
        vector<int> ans;
        for (int i = size - 1; i >= 0; i--) {
            if (res[i] >= maxn) {
                ans.push_back(res[i]);
                maxn = res[i];
            }
        }
        reverse(ans.begin(), ans.end());
        ListNode* node = nullptr, *p = nullptr, *q = nullptr;
        for (auto& i : ans) {
            ListNode* p = new ListNode(i);
            if (node == nullptr) {
                node = p;
            }
            else {
                q->next = p;
            }
            q = p;
        }
        return node;
    }
};