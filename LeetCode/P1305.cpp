// 1305. 两棵二叉搜索树中的所有元素
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
    inline void inOrderTranverse(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inOrderTranverse(root->left, res);
        res.push_back(root->val);
        inOrderTranverse(root->right, res);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans, a, b;
        inOrderTranverse(root1, a);
        inOrderTranverse(root2, b);
        int asize = a.size(), bsize = b.size(), apos = 0, bpos = 0;
        int loop = asize + bsize;
        while (loop--) {
            if (apos == asize) {
                for (int i = bpos; i < bsize; i++) {
                    ans.push_back(b[i]);
                }
                break;
            }
            if (bpos == bsize) {
                for (int i = apos; i < asize; i++) {
                    ans.push_back(a[i]);
                }
                break;
            }
            if (a[apos] <= b[bpos]) {
                ans.push_back(a[apos++]);
            }
            else {
                ans.push_back(b[bpos++]);
            }
        }
        return ans;
    }
};