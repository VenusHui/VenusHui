// 700. 二叉搜索树中的搜索
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root) {
      if (root->val == val)
        return root;
      root = root->val > val ? root->left : root->right;
    }
    return nullptr;
  }
};