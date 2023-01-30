// 226. 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode*)> invert = [&] (TreeNode* node) {
            if (!node) return;
            TreeNode* left = node->left, *right = node->right;
            invert(left);
            invert(right);
            node->left = right;
            node->right = left;
        };
        invert(root);
        return root;
    }
};