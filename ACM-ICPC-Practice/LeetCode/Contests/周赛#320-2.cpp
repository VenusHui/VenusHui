// 6242. 二叉搜索树最近节点查询
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
    vector<int> res;
    inline void calc(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        calc(node->left);
        calc(node->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));
        calc(root);
        sort(res.begin(), res.end());
        int size = res.size();
        for (int i = 0; i < n; i++) {
            if (queries[i] < res[0]) {
                ans[i][0] = -1;
            }
            else {
                int l = 0, r = size - 1;
                while (l < r) {
                    int m = (l + r + 1) >> 1;
                    if (res[m] <= queries[i]) {
                        l = m;
                    }
                    else {
                        r = m - 1;
                    }
                }
                ans[i][0] = res[l];
            }
            if (queries[i] > res[size - 1]) {
                ans[i][1] = -1;
            }
            else {
                int l = 0, r = size - 1;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (res[m] < queries[i]) {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }
                ans[i][1] = res[l];
            }    
        }
        return ans;
    }
};