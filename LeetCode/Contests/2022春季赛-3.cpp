// 3. 二叉搜索树染色
// TLE
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
private:
    int ans;
    bool flag;
    inline void oper(TreeNode* root, int left, int right, int type) {
        if (root == nullptr) {
            return;
        }
        if (abs(root->val) >= left && abs(root->val) <= right) {
            op(root, type);
            oper(root->left, left, right, type);
            oper(root->right, left, right, type);
        }
        else if (abs(root->val) < left) {
            oper(root->right, left, right, type);
        }
        else if (abs(root->val) > right) {
            oper(root->left, left, right, type);
        }
    }
    
    inline void op(TreeNode* root, int type) {
        if (type == 0) {
            root->val = abs(root->val);
        }
        else if (type == 1 && root->val > 0) {
            root->val *= -1;
        }
        else if (type == 1 && root->val == 0) {
            flag = !flag;
        }
    }
    
    inline void calc(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        calc(root->left);
        if (root->val < 0) {
            ans++;
        }
        calc(root->right);
    }
    
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        ans = 0;
        int size = ops.size();
        for (int i = 0; i < size; i++) {
            oper(root, ops[i][1], ops[i][2], ops[i][0]);
        }
        calc(root);
        if (flag) {
            ans++;
        }        
        return ans;
    }
};