// 1026. 节点与其祖先之间的最大差值
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int max_sub = 0;
        function<pair<int, int>(TreeNode*)> calc = [&] (TreeNode* node) {
            if (node == nullptr) return make_pair(-1, -1);
            pair<int, int> ans = make_pair(node->val, node->val);
            pair<int, int> l = calc(node->left), r = calc(node->right);
            ans.first = min(ans.first, min(l.first >= 0 ? l.first : node->val, r.first >= 0 ? r.first : node->val));
            ans.second = max(ans.second, max(l.second >= 0 ? l.second : node->val, r.second >= 0 ? r.second : node->val));
            max_sub = max(max_sub, max(abs(node->val - ans.first), abs(node->val - ans.second)));
            return ans;
        };
        calc(root);
        return max_sub;
    }
};