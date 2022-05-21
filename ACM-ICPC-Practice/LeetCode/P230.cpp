// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 230. 二叉搜索树中第K小的元素
// 二叉搜索树具有如下性质：
// 结点的左子树只包含小于当前结点的数。
// 结点的右子树只包含大于当前结点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

// 方法一：利用二叉搜索树的性质递归
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        function<int(TreeNode *)> findChildNum = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                return 0;
            }
            else
            {
                return findChildNum(node->left) + findChildNum(node->right) + 1;
            }
        };
        int leftNum = findChildNum(root->left);
        if (leftNum + 1 == k)
        {
            return root->val;
        }
        if (k <= leftNum)
        {
            return kthSmallest(root->left, k);
        }
        else
        {
            return kthSmallest(root->right, k - leftNum - 1);
        }
    }
};

// 考虑到中序遍历二叉搜索树恰好所有元素按照大小顺序排列
// 方法二：中序遍历
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        function<void(TreeNode *)> inOrderTranvers = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                return;
            }
            inOrderTranvers(node->left);
            k--;
            if (k == 0)
            {
                ans = node->val;
                return;
            }
            inOrderTranvers(node->right);
        };
        inOrderTranvers(root);
        return ans;
    }
};

// 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第k小的值，你将如何优化算法：
// 方法三：平衡二叉搜索树(AVL树)
// 平衡二叉搜索树具有如下性质：
// 平衡二叉搜索树中每个结点的左子树和右子树的高度最多相差1
// 平衡二叉搜索树的子树也是平衡二叉搜索树；
// 一棵存有n个结点的平衡二叉搜索树的高度是 O(logn)