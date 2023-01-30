// 112. 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        function<bool(TreeNode*, int)> dfs = [&] (TreeNode* node, int value) {
            if (!node) return false;
            if (!node->left && !node->right && value + node->val == targetSum) return true;
            return dfs(node->left, value + node->val) || dfs(node->right, value + node->val);
        };
        return dfs(root, 0);
    }
};