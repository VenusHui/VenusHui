// 剑指 Offer 26. 树的子结构
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
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    bool ans = false;
    if (B == nullptr)
      return ans;
    function<bool(TreeNode *, TreeNode *)> check = [&](TreeNode *a,
                                                       TreeNode *b) {
      if (b == nullptr)
        return true;
      if (a == nullptr)
        return false;
      if (a->val != b->val)
        return false;
      return check(a->left, b->left) && check(a->right, b->right);
    };
    function<void(TreeNode *)> inOrderTranverse = [&](TreeNode *node) {
      if (node == nullptr)
        return;
      inOrderTranverse(node->left);
      if (node->val == B->val) {
        if (check(node, B)) {
          ans = true;
          return;
        }
      }
      inOrderTranverse(node->right);
    };
    inOrderTranverse(A);
    return ans;
  }
};