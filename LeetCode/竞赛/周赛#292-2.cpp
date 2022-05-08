// 6057. 统计值等于子树平均值的节点数
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
private:
    int ans;
    inline pair<int, int> calc(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        pair<int, int> l = calc(root->left), r = calc(root->right);
        if ((root->val + l.first + r.first) / (l.second + r.second + 1) == root->val) {
            ans++;
        }
        return make_pair(root->val + l.first + r.first, l.second + r.second + 1);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        calc(root);
        return ans;
    }
};