// 剑指 Offer 27. 二叉树的镜像
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        function<void(TreeNode*)> convert = [&] (TreeNode* node) {
            if (node == nullptr) return;
            convert(node->left), convert(node->right);
            swap(node->left, node->right);
        };
        convert(root);
        return root;
    }
};