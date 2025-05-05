// 剑指 Offer 28. 对称的二叉树
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
  bool isSymmetric(TreeNode *root) {
    function<bool(TreeNode *, TreeNode *)> check = [&](TreeNode *p,
                                                       TreeNode *q) {
      if (!p && !q)
        return true;
      if (!p || !q)
        return false;
      return p->val == q->val && check(p->left, q->right) &&
             check(p->right, q->left);
    };
    return check(root, root);
  }
};