// 94. 二叉树的中序遍历
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
private:
  vector<int> ans;
  inline void inOrderTranverse(TreeNode *root) {
    if (root == nullptr)
      return;
    inOrderTranverse(root->left);
    ans.push_back(root->val);
    inOrderTranverse(root->right);
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    inOrderTranverse(root);
    return ans;
  }
};