#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename Type>
struct StackNode
{
    Type val;
    StackNode *next;
    StackNode() : next(nullptr) {}
    StackNode(Type x) : val(x), next(nullptr) {}
    StackNode(StackNode<Type> *rNode) : val(rNode->val), next(rNode->next) {}
};

template <typename Type>
class Stack
{
protected:
    StackNode<Type> *topPtr;

public:
    Stack();
    ~Stack();

    // 判断栈是否已满
    bool empty() { return topPtr == nullptr; }

    // 入栈操作
    void push(Type elem);

    // 出栈操作
    void pop();

    // 获取栈顶
    Type &top() { return topPtr->val; }
};

template <typename Type>
Stack<Type>::Stack()
{
    topPtr = nullptr;
}

template <typename Type>
Stack<Type>::~Stack()
{
    StackNode<Type> *tmp = topPtr;
    while (topPtr != nullptr)
    {
        tmp = topPtr->next;
        delete topPtr;
        topPtr = tmp;
    }
}

template <typename Type>
void Stack<Type>::push(Type elem)
{
    StackNode<Type> *newNode = new StackNode<Type>(elem);
    newNode->next = topPtr;
    topPtr = newNode;
}

template <typename Type>
void Stack<Type>::pop()
{
    if (empty())
    {
        return;
    }
    StackNode<Type> *tmp = topPtr;
    topPtr = topPtr->next;
    delete tmp;
}

// template <typename Type>
// Type& Stack<Type>::top(Type &ans)
// {

// }

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
    void preOrderTranvers(BiTreeNode<Type> *curNode);
    void inOrderTranvers(BiTreeNode<Type> *curNode);
    void postOrderTranvers(BiTreeNode<Type> *curNode);
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
void BiTree<Type>::preOrderTranvers(BiTreeNode<Type> *curNode)
{
    if (curNode == nullptr)
    {
        return;
    }
    cout << curNode->val << " ";
    preOrderTranvers(curNode->left);
    preOrderTranvers(curNode->right);
}

template <typename Type>
void BiTree<Type>::inOrderTranvers(BiTreeNode<Type> *curNode)
{
    if (curNode == nullptr)
    {
        return;
    }
    inOrderTranvers(curNode->left);
    cout << curNode->val << " ";
    inOrderTranvers(curNode->right);
}

template <typename Type>
void BiTree<Type>::postOrderTranvers(BiTreeNode<Type> *curNode)
{
    if (curNode == nullptr)
    {
        return;
    }
    postOrderTranvers(curNode->left);
    postOrderTranvers(curNode->right);
    cout << curNode->val << " ";
}

class ExpConvert : BiTree<string>
{
private:
    string temp;                           // 暂存目前正在处理的数据
    string expression;                     // 表达式
    BiTree tree;                           // 表达式转换树
    Stack<BiTreeNode<string> *> dataStack; // 辅助数栈
    Stack<string> operatorStack;           // 辅助符号栈

public:
    ExpConvert();
    ~ExpConvert();
    void createTree();
    void printResult();
};

ExpConvert::ExpConvert()
{
    cout << "请输入表达式：";
    cin >> expression;
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if ((expression.at(i) >= '0' && expression.at(i) <= '9') || expression.at(i) == '.')
        {
            temp += expression.at(i);
        }
        else
        {
            if (!temp.empty())
            {
                BiTreeNode<string> *tmpNode = new BiTreeNode<string>(temp);
                dataStack.push(tmpNode);
            }
            switch (expression.at(i))
            {
            case '+':
            case '-':
                if (operatorStack.empty())
                {
                    operatorStack.push(string(1, expression.at(i)));
                }
                else if (operatorStack.top() == "*" || operatorStack.top() == "/")
                {
                    createTree();
                    operatorStack.push(string(1, expression.at(i)));
                }
                else
                {
                    operatorStack.push(string(1, expression.at(i)));
                }
                break;
            case '*':
            case '/':
                operatorStack.push(string(1, expression.at(i)));
                break;
            case '(':
                operatorStack.push(string(1, expression.at(i)));
                break;
            case ')':
                while (operatorStack.top() != "(")
                {
                    createTree();
                }
                operatorStack.pop();
                break;
            default:
                cout << "Create Tree Error!" << endl;
                break;
            }
            temp.clear();
        }
    }
    if (!temp.empty())
    {
        BiTreeNode<string> *tmpNode = new BiTreeNode<string>(temp);
        dataStack.push(tmpNode);
    }
    while (!operatorStack.empty())
    {
        createTree();
    }
    root = dataStack.top();
    dataStack.pop();
    if (!dataStack.empty())
    {
        cout << "Expression Error!" << endl;
    }
}

ExpConvert::~ExpConvert()
{
}

void ExpConvert::createTree()
{
    BiTreeNode<string> *left = dataStack.top();
    dataStack.pop();
    BiTreeNode<string> *right = dataStack.top();
    dataStack.pop();
    BiTreeNode<string> *curOper = new BiTreeNode<string>(operatorStack.top(), right, left);
    operatorStack.pop();
    dataStack.push(curOper);
}

void ExpConvert::printResult()
{
    cout << "波兰表达式：  ";
    postOrderTranvers(root);
    cout << endl;
    cout << "中缀表达式：  ";
    inOrderTranvers(root);
    cout << endl;
    cout << "逆波兰表达式：";
    preOrderTranvers(root);
    cout << endl;
}

int main()
{
    ExpConvert testInstance;
    testInstance.printResult();
    return 0;
}
