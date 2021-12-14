#include <iostream>
using namespace std;

template <typename Type>
struct BiTreeNode
{
    Type val;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode() : left(nullptr), right(nullptr) {}
    BiTreeNode(Type x) : val(x), left(nullptr), right(nullptr) {}
    BiTreeNode(Type x, BiTreeNode *left, BiTreeNode *right) : val(x), left(left), right(right) {}
    ostream &operator<<(ostream &out)
    {
        out << this->val;
        return out;
    }
};

template <typename Type>
class BiTree
{
protected:
    BiTreeNode<Type> *root;

public:
    BiTree();
    ~BiTree();
    void insert();
    void remove(Type key);
    void preOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
    void inOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
    void postOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
};

template <typename Type>
BiTree<Type>::BiTree()
{
    root = new BiTreeNode<Type>;
}

template <typename Type>
BiTree<Type>::~BiTree()
{
}

template <typename Type>
void BiTree<Type>::preOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    func(curNode);
    preOrderTranvers(curNode->left, func);
    preOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::inOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    inOrderTranvers(curNode->left, func);
    func(curNode);
    inOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::postOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    postOrderTranvers(curNode->left, func);
    postOrderTranvers(curNode->right, func);
    func(curNode);
}

class BiSortTree : BiTree<int>
{
private:
    char oper;

public:
    BiSortTree();
    ~BiSortTree();

    bool setOper();
    char getOper() { return oper; }
};

BiSortTree::BiSortTree()
{
    cout << "**              二叉排序树             **" << endl;
    cout << "=========================================" << endl;
    cout << "**        1 --- 建立二叉排序树         **" << endl;
    cout << "**        2 --- 插入元素               **" << endl;
    cout << "**        3 --- 查询元素               **" << endl;
    cout << "**        4 --- 退出程序               **" << endl;
    cout << "=========================================" << endl;
}

BiSortTree::~BiSortTree()
{
}

bool BiSortTree::setOper()
{
    cout << "Please Input Operation Code:";
    while (cin >> oper)
    {
        if (oper >= '1' && oper <= '4')
        {
            return true;
        }
    }
    return false;
}

int main()
{
    BiSortTree testInstance;
    bool loop = true;
    while (loop && testInstance.setOper())
    {
        switch (testInstance.getOper())
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            loop = false;
            break;
        default:
            cout << "Operation Error!" << endl;
            break;
        }
    }
    return 0;
}