// 429. N 叉树的层序遍历
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    vector<Node *> tmp;
    tmp.push_back(root);
    queue<vector<Node *>> q;
    q.push(tmp);
    vector<int> cnt;
    cnt.push_back(root->val);
    ans.push_back(cnt);
    while (q.size()) {
      tmp = q.front();
      vector<Node *> next;
      cnt.clear();
      q.pop();
      int size = tmp.size();
      for (int i = 0; i < size; i++) {
        int n = tmp[i]->children.size();
        for (int j = 0; j < n; j++) {
          next.push_back(tmp[i]->children[j]);
          cnt.push_back(tmp[i]->children[j]->val);
        }
      }
      if (next.size() != 0) {
        q.push(next);
        ans.push_back(cnt);
      }
    }
    return ans;
  }
};