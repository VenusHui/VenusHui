// 1382. 将二叉搜索树变平衡
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 方法一：中序遍历得到有序数组之后再通过二分建立AVL树
class Solution {
public:
  vector<int> sequence;
  TreeNode *balanceBST(TreeNode *root) {
    function<void(TreeNode *)> inOrderTranverse = [&](TreeNode *node) {
      if (node == nullptr) {
        return;
      }
      inOrderTranverse(node->left);
      sequence.push_back(node->val);
      inOrderTranverse(node->right);
    };
    inOrderTranverse(root);
    int size = sequence.size() - 1;
    TreeNode *newNode = inOrderMakeTree(0, size);
    return newNode;
  }

  TreeNode *inOrderMakeTree(int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *temp = new TreeNode(sequence.at(mid));
    temp->left = inOrderMakeTree(left, mid - 1);
    temp->right = inOrderMakeTree(mid + 1, right);
    return temp;
  }
};