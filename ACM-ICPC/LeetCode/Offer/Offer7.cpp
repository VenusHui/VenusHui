// 剑指 Offer 07. 重建二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        int size = preorder.size();
        map<int, int> inmp, prmp;
        for (int i = 0; i < size; i++) inmp[inorder[i]] = i;
        for (int i = 0; i < size; i++) prmp[preorder[i]] = i;
        if (size == 0) return nullptr;
        function<int(int, int)> calc = [&] (int l, int r) {
            int ans = 0x3f3f3f3f;
            for (int i = l; i <= r; i++) {
                if (prmp.count(inorder[i])) ans = min(ans, prmp[inorder[i]]);
            }
            return ans;
        };
        function<TreeNode*(int, int, int)> build = [&] (int p, int l, int r) {
            if (p == 0x3f3f3f3f) {
                TreeNode* node = nullptr;
                return node;
            }
            int rpos = inmp[preorder[p]];
            return new TreeNode(preorder[p], build(calc(l, rpos - 1), l, rpos - 1), build(calc(rpos + 1, r), rpos + 1, r));
        };
        return build(0, 0, size - 1);
    }
};