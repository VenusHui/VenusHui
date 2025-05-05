// 98. 验证二叉搜索树
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
  vector<int> arr;
  inline void inOrderTranverse(TreeNode *root) {
    if (root == nullptr)
      return;
    inOrderTranverse(root->left);
    arr.push_back(root->val);
    inOrderTranverse(root->right);
  }

public:
  bool isValidBST(TreeNode *root) {
    inOrderTranverse(root);
    int size = arr.size();
    for (int i = 0; i < size; i++) {
      if (i && arr[i] <= arr[i - 1])
        return false;
    }
    return true;
  }
};