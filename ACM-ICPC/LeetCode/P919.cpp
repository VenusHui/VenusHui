// 919. 完全二叉树插入器
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
class CBTInserter {
private:
    TreeNode* root;
public:
    CBTInserter(TreeNode* r) {
        root = r;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            else {
                TreeNode* node = new TreeNode(val);
                tmp->left = node;
                return tmp->val;
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
            else {
                TreeNode* node = new TreeNode(val);
                tmp->right = node;
                return tmp->val;
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */