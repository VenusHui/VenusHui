// 102. 二叉树的层序遍历
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> tmp;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        tmp.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        q.pop();
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};