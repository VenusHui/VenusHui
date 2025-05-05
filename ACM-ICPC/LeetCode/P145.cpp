// 145. 二叉树的后序遍历
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
  inline void postOrderTranverse(TreeNode *root) {
    if (root == nullptr)
      return;
    postOrderTranverse(root->left);
    postOrderTranverse(root->right);
    ans.push_back(root->val);
  }

public:
  vector<int> postorderTraversal(TreeNode *root) {
    postOrderTranverse(root);
    return ans;
  }
};