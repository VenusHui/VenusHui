// 701. 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* node = root;
        while (node) {
            if (val < node->val) {
                if (!node->left) {
                    node->left = new TreeNode(val);
                    break;
                }
                else node = node->left;
            }
            else {
                if (!node->right){
                    node->right = new TreeNode(val);
                    break;
                }
                else node = node->right;
            }
        }
        return root;
    }
};