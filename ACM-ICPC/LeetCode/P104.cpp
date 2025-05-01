// 104. 二叉树的最大深度
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
  int maxDepth(TreeNode *root) {
    int ans = 0;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int depth) {
      if (!node) {
        ans = max(ans, depth);
        return;
      }
      dfs(node->left, depth + 1);
      dfs(node->right, depth + 1);
    };
    dfs(root, 0);
    return ans;
  }
};