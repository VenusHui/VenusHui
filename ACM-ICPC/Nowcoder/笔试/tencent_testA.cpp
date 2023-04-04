/**
 * @platform: Nowcoder_Tencent
 * @problem: tencent_testA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* reorderList(ListNode* head) {
        // write code here
        vector<int> tmp, res;
        while (head) {
            tmp.push_back(head->val);
            head = head->next;
        }
        int size = tmp.size();
        for (int i = 0; i < size; i += 4) {
            if (i + 2 < size) res.push_back(tmp[i + 2]);
            if (i + 3 < size) res.push_back(tmp[i + 3]);
            if (i < size) res.push_back(tmp[i]);
            if (i + 1 < size) res.push_back(tmp[i + 1]);
        }
        ListNode* ans = new ListNode(res[0]);
        ListNode* tnode = ans;
        for (int i = 1; i < size; i++) {
            ListNode* node = new ListNode(res[i]);
            tnode->next = node;
            tnode = node;
        }
        return ans;
    }
};