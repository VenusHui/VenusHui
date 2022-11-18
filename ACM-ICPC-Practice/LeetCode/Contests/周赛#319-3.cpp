// 2471. 逐层排序二叉树所需的最少操作数目
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
    int getMinSwaps(vector<int>& arr) {
        int size = arr.size();
        vector<pair<int, int>> res(size);
        for (int i = 0; i < size; i++) {
            res[i].first = arr[i];
            res[i].second = i;
        }
        sort(res.begin(), res.end());
        int ans = 0;
        vector<bool> vis(size, false);
        for (int i = 0; i < size; i++) {
            if (vis[i] || res[i].second == i) {
                continue;
            }
            int idx = i, tmp = 0;
            while (!vis[idx]) {
                vis[idx] = true;
                tmp++;
                idx = res[idx].second;
            }
            ans += (tmp - 1);
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode* cnt = q.front();
                tmp.push_back(cnt->val);
                q.pop();
                if (cnt->left != nullptr) {
                    q.push(cnt->left);
                }
                if (cnt->right != nullptr) {
                    q.push(cnt->right);
                }
            }
            res.push_back(tmp);
        }
        int ans = 0;
        for (auto& r : res) {
            ans += getMinSwaps(r);
        }
        return ans;
    }
};