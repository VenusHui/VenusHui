#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
using namespace std;

template <typename Type>
struct TreeNode // 树结点，使用孩子兄弟表示法
{
    Type val;
    TreeNode* firstChild;
    TreeNode* nextSibling;
    TreeNode() : firstChild(nullptr), nextSibling(nullptr) {}
    TreeNode(Type x) : val(x), firstChild(nullptr), nextSibling(nullptr) {}
    TreeNode(Type x, TreeNode* firstChild, TreeNode* nextSibling) : val(x), firstChild(firstChild), nextSibling(nextSibling) {}
};

template <typename Type>
class Tree
{
protected:
    TreeNode<Type>* root, * prt;

public:
    Tree();
    ~Tree();

    TreeNode<Type>* getRoot() { return root; }

    // 查找val为key的结点，返回指向该结点的指针
    TreeNode<Type>* find(TreeNode<Type>* pNode, Type key);

    // 向parent结点插入val为key的孩子
    bool insert(TreeNode<Type>* parent, Type key);

    // 删除rNode结点，若其不为叶子结点，则将其孩子一并删除
    bool remove(TreeNode<Type>* pNode);
};

template <typename Type>
Tree<Type>::Tree()
{
    root = nullptr;
    prt = root;
}

template <typename Type>
Tree<Type>::~Tree()
{
}

template <typename Type>
TreeNode<Type>* Tree<Type>::find(TreeNode<Type>* pNode, Type key)
{
    TreeNode<Type>* result = nullptr;
    if (pNode->val == key)
    {
        result = prt = pNode;
    }
    else
    {
        TreeNode<Type>* tmpNode = pNode->firstChild;
        while (tmpNode != nullptr && (result = find(tmpNode, key)) == nullptr)
        {
            tmpNode = tmpNode->nextSibling;
        }
    }
    return result;
}

template <typename Type>
bool Tree<Type>::insert(TreeNode<Type>* parent, Type key)
{
    TreeNode<Type>* child = new TreeNode<Type>(key);
    if (parent->firstChild == nullptr)
    {
        parent->firstChild = child;
    }
    else
    {
        parent = parent->firstChild;
        while (parent->nextSibling != nullptr)
        {
            parent = parent->nextSibling;
        }
        parent->nextSibling = child;
    }
    prt = child;
    return true;
}

template <typename Type>
bool Tree<Type>::remove(TreeNode<Type>* pNode)
{
    if (pNode == nullptr)
    {
        return false;
    }
    if (pNode->firstChild != nullptr)
    {
        function<void(TreeNode<Type>*)> RemoveSubTree = [&](TreeNode<Type>* rNode)
        {
            if (rNode == nullptr)
            {
                return;
            }
            else
            {
                RemoveSubTree(rNode->firstChild);
                RemoveSubTree(rNode->nextSibling);
            }
        };
        RemoveSubTree(pNode->firstChild);
        pNode->firstChild = pNode->nextSibling;
    }
    delete pNode;
    pNode->firstChild = pNode->nextSibling;
    return true;
}

class FamilyTree : Tree<string>
{
private:
    char oper;
    string name;

public:
    FamilyTree();
    ~FamilyTree();

    char GetOper();

    // 输出家谱中成员的子女
    void PrintChildren(TreeNode<string>* curNode);

    // 为已经在家谱中的成员添加子女
    void CompleteTree();

    // 向家谱中添加新成员
    void InsertMember();

    // 对于已经存在于家谱中的成员进行删除
    void RemoveMember();

    // 对于已经存在于家谱中的成员进行更名
    void ChangeName();
};

FamilyTree::FamilyTree()
{
    oper = 0;
    cout << "**             家谱管理系统              **" << endl;
    cout << "===========================================" << endl;
    cout << "**          A --- 完善家谱               **" << endl;
    cout << "**          B --- 添加家庭成员           **" << endl;
    cout << "**          C --- 解散局部家庭           **" << endl;
    cout << "**          D --- 更改家庭成员姓名       **" << endl;
    cout << "**          E --- 退出程序               **" << endl;
    cout << "===========================================" << endl
        << endl;
    cout << "首先建立一个家谱" << endl;
    cout << "请输入祖先的姓名：";
    cin >> name;
    root = new TreeNode<string>(name);
    cout << "此家谱的祖先是：" << root->val << endl;
}

FamilyTree::~FamilyTree()
{
    Tree<string>::~Tree();
}

char FamilyTree::GetOper()
{
    cout << endl
        << "请选择要执行的操作：";
    // 待完善错误处理
    cin >> oper;
    return oper;
}

void FamilyTree::PrintChildren(TreeNode<string>* curNode)
{
    if (curNode->firstChild != nullptr)
    {
        cout << curNode->val << "的第一代子女有：";
        curNode = curNode->firstChild;
        while (curNode != nullptr)
        {
            cout << setw(5) << curNode->val;
            curNode = curNode->nextSibling;
        }
        cout << endl;
    }
    else
    {
        cout << curNode->val << "没有子女" << endl;
    }
}

void FamilyTree::CompleteTree()
{
    cout << "请输入要建立家庭的人的姓名：";
    cin >> name;
    TreeNode<string>* curNode = find(root, name);
    if (curNode != nullptr)
    {
        int childNum;
        cout << "请输入" << name << "的儿女人数：";
        cin >> childNum;
        string* childName = new string[childNum];
        cout << "请依次输入" << name << "儿女的姓名：";
        for (int i = 0; i < childNum; i++)
        {
            cin >> childName[i];
            insert(curNode, childName[i]);
        }
        PrintChildren(curNode);
    }
    else
    {
        cout << name << "不在家谱中，无法为其建立家庭" << endl;
    }
}

void FamilyTree::InsertMember()
{
    cout << "请输入要添加儿子（或女儿）的人的姓名：";
    cin >> name;
    TreeNode<string>* curNode = find(root, name);
    if (curNode != nullptr)
    {
        string childName;
        cout << "请输入" << name << "要添加的儿子（或女儿）的姓名：";
        cin >> childName;
        insert(curNode, childName);
        PrintChildren(curNode);
    }
    else
    {
        cout << name << "不在家谱中，无法为其添加儿女" << endl;
    }
}

void FamilyTree::RemoveMember()
{
    cout << "请输入要解散家庭的人的姓名：";
    cin >> name;
    TreeNode<string>* curNode = find(root, name);
    if (curNode != nullptr)
    {
        PrintChildren(curNode);
        remove(curNode);
        cout << name << "的家庭已解散" << endl;
    }
    else
    {
        cout << name << "不在家谱中，无法解散其家庭" << endl;
    }
}

void FamilyTree::ChangeName()
{
    cout << "请输入要更改姓名的人的目前姓名：";
    cin >> name;
    TreeNode<string>* curNode = find(root, name);
    if (curNode != nullptr)
    {
        string newName;
        cout << "请输入更改后的姓名：";
        cin >> newName;
        if (find(root, newName) != nullptr)
        {
            cout << "已经存在叫" << newName << "的家庭成员，更名会导致家谱混乱" << endl;
            return;
        }
        curNode->val = newName;
        cout << name << "已成功更名为" << newName << endl;
    }
    else
    {
        cout << name << "不在家谱中，无法为其更名" << endl;
    }
}

int main()
{
    bool loop = true;
    FamilyTree testInstance;
    while (loop)
    {
        switch (testInstance.GetOper())
        {
            case 'A':
                testInstance.CompleteTree();
                break;
            case 'B':
                testInstance.InsertMember();
                break;
            case 'C':
                testInstance.RemoveMember();
                break;
            case 'D':
                testInstance.ChangeName();
                break;
            case 'E':
                cout << "退出家谱系统" << endl;
                loop = false;
                break;
            default:
                break;
        }
    }
    return 0;
}
